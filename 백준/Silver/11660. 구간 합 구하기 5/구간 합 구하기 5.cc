#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
using namespace std;

int map[1025][1025] = { 0, };
int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			scanf("%d", &map[i][j]);
			map[i][j] += map[i][j - 1];
		}
	}
	for (int i = 0; i < m; ++i)
	{
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		int sum = 0;
		for (int x = x1; x <= x2; ++x)
		{
			sum += map[x][y2] - map[x][y1 - 1];
		}
		printf("%d\n", sum);
	}
	return 0;
}
