#include <iostream>
#include <stack>
using namespace std;

bool stacks(string& s)
{
    stack<char> c;
    for(int i=0; i<s.size(); i++)
    {
        switch(s[i])
        {
            case '[':
                c.push(s[i]);
                break;

            case '(':
                c.push(s[i]);
                break;
                
            case ']':
                if(c.empty()) return false;
                if(c.top() == '[')
                {
                    c.pop();
                }
                else return false;
                break;
                
            case ')':
                if(c.empty()) return false;
                if(c.top() == '(')
                {
                    c.pop();
                }
                else return false;
                break;
                
            default:
                break;
        }
    }
    if(!c.empty()) return false;
    return true;
}
int main()
{
    while(1)
    {
        string s;
        getline(cin, s,'.');
        if(s.size() == 0) break;
        if(stacks(s)) cout <<"yes\n";
        else cout << "no\n";
        getchar();
    }
    return 0;
}