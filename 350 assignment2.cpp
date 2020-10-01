#include<iostream> 
#include<string>
#include <cstdlib>
using namespace std; 

int main() {
    int state = 1, i = 0;
    string input;

    cout << "Please enter a string to check if it contains a comment:" << endl;
    getline(cin, input);

    while (i < input.length())
    {
        switch(state)
        {
            case 1:
                if (input.at(i) == '/')
                {
                    state = 2;
                    i++;
                }
                else
                {
                    i++;
                }
                break;
            case 2:
                if (input.at(i) == '*')
                {
                    state = 3;
                    i++;
                }
                else
                {
                    state = 1;
                    i++;
                }
                break;
            case 3:
                if (input.at(i) == '*')
                {
                    state = 4;
                    i++;
                }
                else
                {
                    i++;
                }
                break;
            case 4:
                if (input.at(i) == '/')
                {
                    state = 5;
                    i++;
                }
                else
                {
                    state = 3;
                    i++;
                }
                break;
            case 5:
                i++;
                break;
        }
    }

    if (state == 5)
    {
        cout << endl << "The input line contains a comment";
    }
    else
    {
        cout << endl << "The input line does not contain a comment";
    }
    
    cout << endl << endl;
    system("pause");
    return 0;
}