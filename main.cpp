#include <iostream>
#include <vector>
#include <time.h>
using namespace std; 

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

public:
    //constructor
    Graph(int n)
    {
        N = n;
        tree.resize(N);
    }

    Graph(int n, int p)
    {
        N = n;
        tree.resize(N);

        //loop trhough every combination, adding a branch with a random percentage p
        for (int i = 0; i < N; i++)
        {
            for (int j = i; j < N; j++)
            {
                if (i != j && p >= rand() % 100 + 1)
                {
                    add(i,j);
                }
            }
        }
    }

    ~Graph()
    {
        tree.clear();
    }
    
    void add(int u, int v)
    {
        tree[u].push_back(v); 
        tree[v].push_back(u);
    }

    //loop through the matrix outputting the adjacency lists
    void print() 
    { 
        for (int n = 0; n < N; ++n) 
        { 
            cout << endl << "Adjacency list of vertex " << n << endl << "head"; 
            for (auto x : tree[n]) 
            {
                cout << " -> " << x; 
            }
            cout << endl; 
        } 
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

int main() 
{
    start();
    int p = 30; //percent chance of branch existing

    Graph trees[5] = {tree2a(), tree2b(), tree3a(), tree3b(), tree4()};
    Graph randomTrees[10] = {Graph(30,p), Graph(60,p), Graph(90,p), Graph(120,p), Graph(150,p), Graph(180,p), Graph(210,p), Graph(240,p), Graph(270,p), Graph(300,p)};

    // for (int i = 0; i < 5; i++)
    // {
    //     trees[i].print();
    //     cout << endl << endl << "NEXT TREE" << endl << endl;
    // }

    // for (int i = 0; i < 10; i++)
    // {
    //     randomTrees[i].print();
    //     cout << endl << endl << "NEXT TREE" << endl << endl;
    // }
    
    pause();
    return 0;
}