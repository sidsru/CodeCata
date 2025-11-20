#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n,m;
    cin >> n >> m;
    vector<int> v(n+1);
    v[0] = 0;
    for(int i=1; i<=n; i++)
    {
        int a;
        cin >> a;
        v[i] = v[i-1] + a;
    }
    for(int i=0; i<m; i++)
    {
        int x, y, sum;
        cin >> x >> y;
        sum = v[y] - v[x-1];
        cout << sum << '\n';
    }
    return 0;
}