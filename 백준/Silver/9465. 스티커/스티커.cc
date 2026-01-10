#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
using namespace std;
inline int Max(const int a, const int b)
{
	return a > b ? a : b;
}
void DP(int m[][100001], const int n)
{
	for (int i = 2; i <= n; ++i)
	{
		m[0][i] += Max(m[1][i - 1], m[1][i - 2]);
		m[1][i] += Max(m[0][i - 1], m[0][i - 2]);
	}
	return;
}
int main()
{
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i)
	{
		int n;
		scanf("%d", &n);
		int m[2][100001] = { 0 ,};
		for (int j = 0; j < 2; ++j)
		{
			for (int k = 1; k <= n; ++k)
			{
				scanf("%d", &m[j][k]);
			}
		}
		DP(m, n);
		printf("%d\n", Max(m[0][n], m[1][n]));
	}
	return 0;
}
