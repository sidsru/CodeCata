#include <iostream>
#include <stack>
using namespace std;
int main ()
{
    stack<int> stacks;
    int n;
    cin >> n;
    for (int i=0; i<n; i++)
    {
        string s;
        int a;
        cin >> s;
        if(s == "push")
        {
            cin >> a;
            stacks.push(a);
        }
        else if(s == "pop")
        {
            if(stacks.empty()) cout << -1 << "\n";
            else 
            {
                cout << stacks.top() << "\n";
                stacks.pop();
            }
        }
        else if(s == "size") cout << stacks.size() << "\n";
        else if(s == "empty")
        {
            if(stacks.empty()) cout << 1 << "\n";
            else cout << 0 << "\n";
        }
        else if(s == "top") 
        {
            if(stacks.empty()) cout << -1 << "\n";
            else cout << stacks.top() << "\n";
        }
    }
    return 0;
}