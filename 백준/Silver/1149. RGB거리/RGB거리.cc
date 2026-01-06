#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
using namespace std;
inline int min(const int a, const int b)
{
	return a > b ? b : a;
}
int main()
{
	int n, dp[1001][3];
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d %d %d", &dp[i][0], &dp[i][1], &dp[i][2]);
	}
	for (int i = 1; i < n; ++i)
	{
		dp[i][0] += min(dp[i-1][1], dp[i - 1][2]);
		dp[i][1] += min(dp[i-1][0], dp[i - 1][2]);
		dp[i][2] += min(dp[i-1][0], dp[i - 1][1]);
	}
	int answer = min(min(dp[n-1][0], dp[n-1][1]), dp[n-1][2]);
	printf("%d", answer);
	return 0;
}
