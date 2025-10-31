#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int n;
    cin >> n;
    queue<int> q;
    for(int i=0; i<n; i++)
    {
        string s;
        int a;
        cin >> s;
        if(s == "push")
        {
            cin >> a;
            q.push(a);
        }
        else if(s == "pop")
        {
            if(q.empty()) cout << -1 << "\n";
            else 
            {
                cout << q.front() << "\n";
                q.pop();
            }
        }
        else if(s == "size") cout << q.size() << "\n";
        else if(s == "empty")
        {
            if(q.empty()) cout << 1 << "\n";
            else cout << 0 << "\n";
        }
        else if(s == "front") 
        {
            if(q.empty()) cout << -1 << "\n";
            else cout << q.front() << "\n";
        }
        else if(s == "back") 
        {
            if(q.empty()) cout << -1 << "\n";
            else cout << q.back() << "\n";
        }
    }
    return 0;
}