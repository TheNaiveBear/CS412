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
    cout << endl << endl << "Enter Anything:" << endl;
    string x;
    getline(cin,x,'\n');
    cout << endl << "You Entered: " << x << endl;
    
    
    
    cout << endl << "win" << endl;
    system("pause");
    return 0;
}