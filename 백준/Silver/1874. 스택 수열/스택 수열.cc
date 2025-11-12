#include <iostream>
#include <stack>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m, j = 1;
    stack<int> stacks;
    queue<int> q;
    vector<char> v;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> m;
        q.push(m);
    }
    stacks.push(j);
    v.push_back('+');
    while(j <= n)
    {
        if(q.empty()) break;
        if(!stacks.empty() && stacks.top() == q.front())
        {
            v.push_back('-');
            q.pop();
            stacks.pop();
        }
        else
        {
            v.push_back('+');
            ++j;
            stacks.push(j);
        }
    }
    if(q.empty())
    {
        for(char c : v)
        {
            cout << c << "\n";
        }
    }
    else
        cout << "NO\n";
}