#include <iostream> 
#include <string>
#include <cstdlib>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include <limits.h> 
#include <list> 
#include <stack> 
#define NINF INT_MIN 
using namespace std; 

//class to contain the adjecency list nodes
class AdjNode
{
    int v;
    int weight;
public:
    AdjNode(int _v, int _w)
    {
        v = _v;
        weight = _w;
    }
    int getV()
    {
        return v;
    }
    int getWeight()
    {
        return weight;
    }
};

//class to represent a graph from the list
class Graph 
{
    //number of verticies
    int V;
    //pointer to array containing the list
    list<AdjNode>* adj;
    //a sort function
    void Sort(int v, bool visited[], stack<int>& Stack)
    {
        //marc current as visited
        visited[v] = true;

        //recur in all adjecent verticies
        list<AdjNode>::iterator i;  
        for (i = adj[v].begin(); i != adj[v].end(); ++i) 
        {  
            AdjNode node = *i;  
            if (!visited[node.getV()])
            {
                Sort(node.getV(), visited, Stack);
            }    
        }
        //push the current node to the stack
        Stack.push(v);
    }

public:
    //constructer
    Graph(int V)
    {
        this -> V = V;
        adj = new list<AdjNode>[V];
    }
    //constructer w/ random graph generation
    Graph(int V, int percent)
    {
        this -> V = V;
        adj = new list<AdjNode>[V];

        srand (time(NULL));
        
        for (int i = 0; i < V; i++)
        {
            for (int j = i; j < V; j++)
            {
                if (percent >= rand() % 100 + 1)
                {
                    addEdge(i,j,rand() % (V/10) + 1);
                }
            }
        } 
    }
    //destructer
    ~Graph()
    {
        delete [] adj;
    }
    //function to add an edge
    void addEdge(int u, int v, int weight)
    {
        AdjNode node1(v, weight);
        AdjNode node2(u, weight);
        //Add V to u list
        adj[u].push_back(node1);
        //since graph is undirected
        adj[v].push_back(node2);
    }

    void longestPath(int s)
    {
        stack<int> Stack;  
        vector<int> dist;
        vector<int> num;
        dist.resize(V);  
        num.resize(V);  
        //mark all nodes as not visited
        bool* visited = new bool[V];  
        for (int i = 0; i < V; i++)  
            visited[i] = false;  
         
         //call the sort
        for (int i = 0; i < V; i++)  
            if (visited[i] == false)  
                Sort(i, visited, Stack);  
        
        //initalize all the nodes
        for (int i = 0; i < V; i++) 
        { 
            dist[i] = NINF;  
            num[i] = 1;
        }
        dist[s] = 0;  
        
        //this is the loop where the length is calculated. this is what would have to be diffrent to calculate the longest path of a single weight
        //im not sure how to get it to look for a path of a single weight without destroying the programs runtime
        while (Stack.empty() == false) {   
            //get the next node forom the sort
            int u = Stack.top();  
            Stack.pop();  
            //calculate the weights
            list<AdjNode>::iterator i;  
            if (dist[u] != NINF) {  
                for (i = adj[u].begin(); i != adj[u].end(); ++i)  
                    if (dist[i->getV()] < dist[u] + i->getWeight())
                    {
                        dist[i->getV()] = dist[u] + i->getWeight();
                        num[u]++;
                    }  
            }  
        }  
         
         //loop through the graph searching for the greatest weight
        int hI = 0, hL = 0;
        for (int i = 0; i < V; i++)  
        { 
            if (dist[i] > hI)
            {
                hI = dist[i];
                hL = num[i];
            }
        }

        cout << endl << "The longest path from node " << s << " contains " << hL << " nodes with a total weighted length of " << hI;
        
        delete [] visited; 
    }
};

int main()
{
    //the chance that any two nodes will be connected
    int percent, n;
    bool val, cont = true;
    string ans;

    int start_node = 1;

    cout << "Input percent chance any two nodes will link: ";
    cin >> percent;
    cout << endl;
    
    while (cont == true)
    {
        cout << "Input number of verticies: ";
        cin >> n;

        Graph g(n,percent);
        g.longestPath(start_node);

        //loop to loop through the program for multiple entries
        cout << endl << endl << "Continue? (y/n): ";
        val = false;
        while (val == false)
        {
            getline(cin,ans,'\n');
            if (ans == "y")
            {
                cout << endl;
                val = true;
            }
            else if (ans == "n")
            {
                cont = false;
                val = true;
            }
        }
    }

    cout << endl << endl;
    std::system("pause");
    return 0;
}