#include <stdio.h>
using namespace std;
inline int Min(int a, int b)
{
    return a < b ? a : b;
}

int main()
{
    int dp[50001];
    int n;
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
    {
        dp[i] = dp[i-1] + 1;
        for(int j=2; j*j<=i; j++)
        {
            dp[i] = Min(dp[i], dp[i - j*j] + 1);
        }
    }
    printf("%d",dp[n]);
    return 0;
}