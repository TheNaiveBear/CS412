#include <iostream>
#include <vector>
#include <time.h>
using namespace std; 

//#define TEST_OUTPUT_LIST
//#define TEST_OUTPUT_MATRIX

void pause()
{
    cout << endl << endl;
    system("pause");
}

void start()
{
    srand (time(NULL));
}

class Graph
{
    vector<vector<int>> tree; //matrix holding adjecency list
    int N; //number of vertacies
    
    int U; //root

    //random number generator
    int random(int l, int r) 
    { 
        return l + (rand() % (r - l + 1)); 
    } 

    void nodeRecursive(vector<vector<int>> tree, vector<vector<int>> &subtree, int u)
    {
        for (int i = 0; i < tree.size(); i++)
        {
            if (tree[u][i] == 1)
            {
                subtree[u][i] = 1;
                subtree[i][u] = 1;
                tree[u][i] = 0;
                tree[i][u] = 0;
                nodeRecursive(tree, subtree, i);
            }
        }
    }

    int c1(vector<vector<int>> subtree, vector<int> newForest)
    {
        int k = 0;
        vector<vector<int>> newForest2;
        for (int i = 0; i < newForest.size(); i++)
        {
            newForest2.resize(subtree.size(), vector<int>(subtree.size()));
            nodeRecursive(subtree, newForest2, newForest[i]);
            k += c1star(newForest2);
            newForest2.clear();
        }
        return k;
    }

    int c1star(vector<vector<int>> subtree)
    {
        //therom states the cop# of a graph with no intersecting edges is maximum 3
        //as this is a tree, there will be no overlapping edges
        //above this, another therom states the minimum number is the maximum degree of the graph
        //knowing both of these, each subtree has a cop number between 1 and 3, depending on the maximum degree
        //if highest degree is 2, cop number is 1. otherwise 3

        int temp;
        int k = 0;

        for (int i = 0; i < subtree.size(); i++)
        {
            temp = 0;
            for (int j = 0; j < subtree.size(); j++)
            {
                if (subtree[i][j] == 1)
                {
                    temp++;
                }
            }
            if (temp == 2)
            {
                temp = 1;
            }
            if (temp > k )
            {
                k = temp;
            }
        }
        if (k > 3)
        {
            k = 3;
        }
        return k;
    }

    bool kPre(vector<vector<int>> subtree, int u, int k)
    {
        vector<vector<int>> newsubtree(subtree);
        vector<int> newForest, newForest2;
        int size = 0;

        for (int i = 0; i < subtree.size(); i++)
        {
            if (subtree[u][i] == 1)
            {
                subtree[u][i] = 0;
                subtree[i][u] = 0;
                newForest.resize(newForest.size() + 1);
                newForest[newForest.size()-1] = i;
            }
        }

        size = newForest.size();
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < subtree.size(); j++)
            {
                if (subtree[newForest[i]][j] == 1)
                {
                    subtree[j][newForest[i]] = 0;
                    subtree[newForest[i]][j] = 0;
                    newForest2.resize(newForest2.size() + 1);
                    newForest2[newForest2.size()-1] = j;
                }
            }
        }

        newForest.clear();
        size = newForest2.size();
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < subtree.size(); j++)
            {
                if (subtree[newForest2[i]][j] == 1)
                {
                    subtree[j][newForest2[i]] = 0;
                    subtree[newForest2[i]][j] = 0;
                    newForest.resize(newForest.size() + 1);
                    newForest[newForest.size()-1] = j;
                }
            }
        }

        size = newsubtree.size();
        newsubtree.resize((size * 2) + 1, vector<int>((size * 2) + 1));
        for (int i = 0; i < (newsubtree.size()-1)/2; i++)
        {
            for (int j = i; j < (newsubtree.size()-1)/2; j++)
            {
                newsubtree[i + size][j + size] = newsubtree[i][j];
                newsubtree[j + size][i + size] = newsubtree[j][i];
            }
        }
        newsubtree[newsubtree.size() - 1][u] = 1;
        newsubtree[u][newsubtree.size() - 1] = 1;
        newsubtree[newsubtree.size() - 1][u + size] = 1;
        newsubtree[u + size][newsubtree.size() - 1] = 1;
        newForest2.clear();
        newForest2.resize(1);
        newForest2[0] = newsubtree.size() - 1;

        //subtree = v-N[2]
        //newForest = v-N[2] start nodes
        if (c1star(subtree) == k && c1(newsubtree, newForest2))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool kWeak()
    {

    }

    int Ipb(vector<vector<int>> subtree, int u, int k)
    {
        if (kPre(subtree, u, k) == true)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    int Iwb(vector<vector<int>> subtree, int u, int k)
    {

    }

    int J(vector<vector<int>> subtree, int u, int k)
    {

    }

    int Jw(vector<vector<int>> subtree, int u, int k)
    {

    }

    int Conpb(vector<vector<int>> subtree, vector<int> newForest, int k)
    {
        int count = 0;
        vector<vector<int>> newForest2;
        for (int i = 0; i < newForest.size(); i++)
        {
            newForest2.resize(subtree.size(), vector<int>(subtree.size()));
            nodeRecursive(subtree, newForest2, newForest[i]);
            count += Ipb(newForest2, newForest[i], k);
            newForest2.clear();
        }
        return count;
    }

    int Conwb(vector<vector<int>> subtree, vector<int> newForest, int k)
    {

    }

    int h(vector<vector<int>> subtree, vector<int> newForest, int k)
    {

    }

    int hw(vector<vector<int>> subtree, vector<int> newForest, int k)
    {

    }

    void computeLabel(vector<vector<int>> subtree, int u)
    {
        vector<int> newForest;

        for (int i = 0; i < subtree.size(); i++)
        {
            if (subtree[u][i] == 1)
            {
                subtree[u][i] = 0;
                subtree[i][u] = 0;
                newForest.resize(newForest.size() + 1);
                newForest[newForest.size()-1] = i;
            }
        }

        int k = c1star(subtree);
        
        //cout << Conpb(subtree, newForest, k);
    }
public:
    //constructor
    Graph(int n)
    {
        N = n;
        tree.resize(N, vector<int>(N));
    }

    //generate a random tree
    void generate()
    {
        vector<int> genTree;
        genTree.resize(N);
        vector<int> vertices;
        vertices.resize(N + 2);

        //filling with random values
        for(int i = 0; i < N; i++)
        {
            genTree[i] = 1 + random(0, N-2);
        }

        //initialize the vertex
        for (int i = 0; i < N + 2 ; i++)
        {
            vertices[i] = 0;
        }

        //Find number of occurances a node connects to another
        for (int i = 0; i < N; i++)
        {
            vertices[genTree[i] - 1] += 1;
        }
    
        int j = 0; 
    
        //find smallest label not in tree
        for (int i = 0; i < N; i++)  
        { 
            for (j = 0; j < N; j++) 
            { 
                //if j+1 is not in tree
                if (vertices[j] == 0) 
                { 
                    //remove from tree and print pair
                    vertices[j] = -1;
                    add(j,genTree[i]);
                    vertices[genTree[i] - 1]--; 
                    break; 
                } 
            } 
        } 
    
        j = 0; 
        int x,y;
    
        //prints the last element
        for (int i = 0; i < N+2; i++) 
        { 
            if (vertices[i] == 0 && j == 0) 
            { 
                x = i-2;
                j++; 
            } 
            else if (vertices[i] == 0 && j == 1) 
            {
                y = i - 2;
            }
        } 
        add(x,y);
    }

    //add an edge to the tree
    void add(int u, int v)
    {
        tree[u][v] = 1;
        tree[v][u] = 1;
    }

    //set the root
    void setRoot(int u)
    {
        U = u;
    }
    void setRoot()
    {
        int u;
        while (true)
        {
            cout << "Please Enter a Root: ";
            cin >> u;
            if (u < N && u >= 0 &! cin.fail())
            {
                U = u;
                break;
            }
            cout << "Error" << endl;
			cin.clear();
			cin.ignore(10000, '\n');
        }
    }

    //loop through the matrix outputting the adjacency lists
    void print() 
    { 
        for (int n = 0; n < N; ++n) 
        { 
            cout << endl << "Adjacency list of vertex " << n << endl << "head"; 
            for (int m = 0; m < N; m++)
            {
                if (tree[n][m] == 1)
                {
                    cout << " -> " << m; 
                }
            }
            cout << endl; 
        } 
    } 

    //printthe trees matrix
    void printMatrix()
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cout << tree[i][j] << " ";
            }
            cout << endl;
        }
    }

    void test()
    {
        computeLabel(tree, 0);
    }

    void algorithm1 ()
    {

    }
};

Graph tree2a()
{
    Graph tree(12);
    tree.add(0,1);
    tree.add(1,2);
    tree.add(2,3);
    tree.add(0,4);
    tree.add(4,5);
    tree.add(5,6);
    tree.add(6,7);
    tree.add(0,8);
    tree.add(8,9);
    tree.add(9,10);
    tree.add(10,11);
    return tree;
}

Graph tree2b()
{
    Graph tree(13);
    tree.add(0,1);
    tree.add(1,2);
    tree.add(2,3);
    tree.add(3,4);
    tree.add(0,5);
    tree.add(5,6);
    tree.add(6,7);
    tree.add(7,8);
    tree.add(0,9);
    tree.add(9,10);
    tree.add(10,11);
    tree.add(11,12);
    return tree;
}

Graph tree3a()
{
    Graph tree(74);
    tree.add(0,1);
    tree.add(1,2);
    tree.add(2,3);
    tree.add(3,4);
    tree.add(4,5);
    tree.add(5,6);
    tree.add(5,7);
    tree.add(5,8);
    tree.add(8,9);
    tree.add(8,10);
    tree.add(10,11);
    tree.add(11,12);
    tree.add(4,13);
    tree.add(13,14);
    tree.add(13,15);
    tree.add(4,16);
    tree.add(16,17);
    tree.add(16,18);
    tree.add(16,19);
    tree.add(16,20);
    tree.add(20,21);
    tree.add(21,22);
    tree.add(22,23);
    tree.add(20,24);
    tree.add(24,25);
    tree.add(24,26);
    tree.add(4,27);
    tree.add(27,28);
    tree.add(27,29);
    tree.add(29,30);
    tree.add(29,31);
    tree.add(27,32);
    tree.add(32,33);
    tree.add(32,34);
    tree.add(34,35);
    tree.add(34,36);
    tree.add(0,37);
    tree.add(37,38);
    tree.add(38,39);
    tree.add(39,40);
    tree.add(40,41);
    tree.add(41,42);
    tree.add(42,43);
    tree.add(43,44);
    tree.add(42,45);
    tree.add(45,46);
    tree.add(42,47);
    tree.add(47,48);
    tree.add(47,49);
    tree.add(49,50);
    tree.add(41,51);
    tree.add(51,52);
    tree.add(51,53);
    tree.add(51,54);
    tree.add(54,55);
    tree.add(54,56);
    tree.add(54,57);
    tree.add(57,58);
    tree.add(57,59);
    tree.add(41,60);
    tree.add(41,61);
    tree.add(41,62);
    tree.add(62,63);
    tree.add(62,64);
    tree.add(64,65);
    tree.add(64,66);
    tree.add(62,67);
    tree.add(67,68);
    tree.add(68,69);
    tree.add(67,70);
    tree.add(67,71);
    tree.add(71,72);
    tree.add(71,73);
    tree.setRoot(0);
    return tree;
}

Graph tree3b()
{
    Graph tree(74);
    tree.add(0,1);
    tree.add(1,2);
    tree.add(1,3);
    tree.add(1,4);
    tree.add(4,5);
    tree.add(4,6);
    tree.add(6,7);
    tree.add(6,8);
    tree.add(0,12);
    tree.add(12,13);
    tree.add(12,14);
    tree.add(12,15);
    tree.add(12,16);
    tree.add(16,17);
    tree.add(17,18);
    tree.add(17,19);
    tree.add(16,20);
    tree.add(20,21);
    tree.add(20,22);
    tree.add(0,23);
    tree.add(23,24);
    tree.add(23,25);
    tree.add(25,26);
    tree.add(25,27);
    tree.add(23,28);
    tree.add(28,29);
    tree.add(28,30);
    tree.add(30,31);
    tree.add(30,32);
    tree.add(0,33);
    tree.add(33,34);
    tree.add(34,35);
    tree.add(35,36);
    tree.add(36,37);
    tree.add(37,38);
    tree.add(38,39);
    tree.add(39,40);
    tree.add(40,41);
    tree.add(41,42);
    tree.add(42,43);
    tree.add(43,44);
    tree.add(42,45);
    tree.add(45,46);
    tree.add(42,47);
    tree.add(47,48);
    tree.add(47,49);
    tree.add(49,50);
    tree.add(41,51);
    tree.add(51,52);
    tree.add(51,53);
    tree.add(51,54);
    tree.add(54,55);
    tree.add(54,56);
    tree.add(54,57);
    tree.add(57,58);
    tree.add(57,59);
    tree.add(41,60);
    tree.add(41,61);
    tree.add(41,62);
    tree.add(62,63);
    tree.add(62,64);
    tree.add(64,65);
    tree.add(64,66);
    tree.add(62,67);
    tree.add(67,68);
    tree.add(68,69);
    tree.add(67,70);
    tree.add(67,71);
    tree.add(71,72);
    tree.add(71,73);
    return tree;
}

Graph tree4()
{
    Graph tree(12);
    tree.add(0,1);
    tree.add(0,2);
    tree.add(0,3);
    tree.add(0,4);
    tree.add(0,5);
    tree.add(3,6);
    tree.add(3,7);
    tree.add(4,8);
    tree.add(4,9);
    tree.add(5,10);
    tree.add(5,11);
    return tree;
}

Graph tree5(int n)
{
    Graph tree(n);
    tree.generate();
    return tree;
}

int main() 
{
    start();

    Graph trees[5] = {tree2a(), tree2b(), tree3a(), tree3b(), tree4()};
    Graph randomTrees[10] = {tree5(30), tree5(60), tree5(90), tree5(120), tree5(150), tree5(180), tree5(210), tree5(240), tree5(270), tree5(300)};

    #ifdef TEST_OUTPUT_LIST
    for (int i = 0; i < 5; i++)
    {
        trees[i].print();
        cout << endl << endl << "NEXT TREE" << endl << endl;
    }
    for (int i = 0; i < 4; i++)
    {
        randomTrees[i].print();
        cout << endl << endl << "NEXT TREE" << endl << endl;
    }
    #endif
    #ifdef TEST_OUTPUT_MATRIX
    for (int i = 0; i < 5; i++)
    {
        trees[i].printMatrix();
        cout << endl << endl << "NEXT TREE" << endl << endl;
    }
    for (int i = 0; i < 4; i++)
    {
        randomTrees[i].printMatrix();
        cout << endl << endl << "NEXT TREE" << endl << endl;
    }
    #endif

    //trees[0].print();
    trees[0].test();

    pause();
    return 0;
}