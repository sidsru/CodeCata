#include <iostream>
#include <stack>
using namespace std;

bool chack(string s)
{
    stack<char> stack;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]=='(') 
        {
            stack.push(s[i]);
        }
        else if(s[i]==')')
        {
            if(stack.empty()) return false;
            stack.pop();
        }
    }
    if(!stack.empty()) return false;
    return true;
}

int main ()
{
    int n;
    cin >> n;
    string s;
    for(int i=0; i<n; i++)
    {
        cin >> s;
        if(chack(s)) cout << "YES\n";
        else cout << "NO\n";
    }
}