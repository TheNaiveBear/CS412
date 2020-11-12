#include <iostream> 
#include <string>
#include <vector>
#include <time.h>
#include <algorithm>
using namespace std; 

typedef  pair<int, int> iPair; 

struct DSets 
{ 
    int *parent, *rnk; 
    int n; 
  
    // constructor
    DSets(int n) 
    { 
        // give memory
        this->n = n; 
        parent = new int[n+1]; 
        rnk = new int[n+1]; 
  
        //set all vertacies to 0
        for (int i = 0; i <= n; i++) 
        { 
            rnk[i] = 0; 
  
            //every element is its owbn parent
            parent[i] = i; 
        } 
    } 
  
    //find the parent node of u
    int find(int u) 
    { 
        if (u != parent[u]) 
            parent[u] = find(parent[u]); 
        return parent[u]; 
    } 
    
    //merge by rank
    void merge(int x, int y) 
    { 
        x = find(x), y = find(y); 
  
        if (rnk[x] > rnk[y]) 
            parent[y] = x; 
        else //if rnk(x) <= rnk(y)
            parent[x] = y; 
  
        if (rnk[x] == rnk[y]) 
            rnk[y]++; 
    } 
}; 

//class to represent a graph from the list
class Graph 
{
    //number of verticies
    int V;

    vector<pair<int, iPair>> edges;

public:
    //constructer
    Graph(int V) 
    { 
        this -> V = V; 
    }
    //constructer w/ random graph generation
    Graph(int V, int percent)
    {
        this -> V = V;

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

    //function to add an edge
    void addEdge(int u, int v, int w) 
    { 
        edges.push_back({w, {u, v}}); 
    } 

    //function to find MST
    int MST()
    {
        int mst_wt = 0;
   
        //sort edges in increasing order
        sort(edges.begin(), edges.end()); 
    
        //create disjoint sets
        DSets ds(V); 

        //itterate trhough the sorted edges
        vector< pair<int, iPair> >::iterator it; 
        for (it=edges.begin(); it!=edges.end(); it++) 
        { 
            int u = it->second.first; 
            int v = it->second.second; 
    
            int set_u = ds.find(u); 
            int set_v = ds.find(v); 

            //check if a cycle
            if (set_u != set_v) 
            { 
                //print current edge as its in MST
                cout << u << " - " << v << endl; 

                //update weight
                mst_wt += it->first; 

                //merge the two sets
                ds.merge(set_u, set_v); 
            } 
        } 
    
        return mst_wt; 
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
    
    //loop to run program multiple times
    while (cont == true)
    {
        cout << "Input number of verticies: ";
        cin >> n;

        Graph g(n,percent);
        
        cout << "Edges of MST are \n"; 
        int mst_wt = g.MST(); 
  
        cout << "\nWeight of MST is " << mst_wt; 

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