#include <iostream>
#include <algorithm>
using namespace std;
/*inline int Min(int a, int b)
{
    return a < b ? a : b;
}*/

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int dp[50001];
    int n;
    cin >> n;
    for(int i=1; i<=n; i++)
    {
        dp[i] = dp[i-1] + 1;
        for(int j=2; j*j<=i; j++)
        {
            dp[i] = min(dp[i], dp[i - j*j] + 1);
        }
    }
    
    cout << dp[n] << '\n';
}