#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
using namespace std;
int main()
{
	int n;
	int dp[502][502] = {0, };
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			scanf("%d", &dp[i][j]);
			dp[i][j] += dp[i - 1][j] > dp[i - 1][j - 1] ? dp[i - 1][j] : dp[i - 1][j - 1];
		}
	}
	int answer = 0;
	for (int i = 1; i <= n; ++i)
	{
		if(answer < dp[n][i])
			answer = dp[n][i];
	}
	printf("%d\n", answer);
	return 0;
}
