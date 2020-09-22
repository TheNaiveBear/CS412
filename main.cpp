#include<iostream> 
#include<vector>
#include<time.h>
#include<string>
using namespace std; 

//random number generator
int random(int l, int r) 
{ 
    return l + (rand() % (r - l + 1)); 
} 

//generates an array of length n, and fills array with values <= n
vector<int> generateArray(int n){
    //generating array
    vector<int> tree;
    tree.resize(n);

    //filling with random values
    for(int i = 0; i < n; i++)
    {
        tree[i] = 1 + random(0, n);
    }

    return tree;
}

void printTree(vector<int> tree, int n){
    vector<int> vertices;
    vertices.resize(n + 2);

    //initialize the vertex
    for (int i = 0; i < n + 2 ; i++)
    {
        vertices[i] = 0;
    }

    //Find number of occurances a node connects to another
    for (int i = 0; i < n; i++)
    {
        vertices[tree[i] - 1] += 1;
    }

    cout << endl << "The Adjacent List is:" << endl; 
  
    int j = 0; 
  
    //find smallest label not in tree
    for (int i = 0; i < n; i++)  
    { 
        for (j = 0; j < n + 2; j++) 
        { 
            //if j+1 is not in tree
            if (vertices[j] == 0) 
            { 
                //remove from tree and print pair
                vertices[j] = -1; 
                cout<<"(" << (j + 1) << ", " << tree[i] << ") "; 
  
                vertices[tree[i] - 1]--; 
  
                break; 
            } 
        } 
    } 
  
    j = 0; 
  
    //prints the last element
    for (int i = 0; i < n + 2; i++) 
    { 
        if (vertices[i] == 0 && j == 0) 
        { 
            cout << "(" << (i + 1) << ", "; 
            j++; 
        } 
        else if (vertices[i] == 0 && j == 1) 
            cout << (i + 1) << ")\n"; 
    } 
    return;
}

int main() {
    srand(time(0));

    int n;
    bool cont = true;
    bool val;
    string ans;
    
    while (cont == true)
    {
        cout << "Input number of verticies: ";
        cin >> n;

        vector<int> tree;
        tree.resize(n);
        tree = generateArray(n);
        printTree(tree, n);

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
    system("pause");
    return 0;
}