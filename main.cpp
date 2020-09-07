#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<string> msg {"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};

    for (const string& word : msg)
    {
        cout << word << " ";
    }
    cout << endl << endl;
    string x;
    getline(cin,x,'\n');
    cout << endl << x << endl;
    
    
    
    cout << endl;
    system("pause");
    return 0;
}