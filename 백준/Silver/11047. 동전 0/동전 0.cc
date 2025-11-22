#include <iostream>
#include <stack>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    stack<int> money;
    int n, m;
    cin >> n >> m;
    for(int i=0; i<n; i++)
    {
        int a;
        cin >> a;
        money.push(a);
    }
    int sum = 0;
    while(m || !money.empty())
    {
        sum += m / money.top();
        m %= money.top();
        money.pop();
    }
    cout << sum;
}