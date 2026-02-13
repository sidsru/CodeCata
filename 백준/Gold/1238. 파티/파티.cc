// 백준
#include <iostream>
#define endl '\n'
using namespace std;
constexpr int INF = (~0U >> 1);
int answer = 0;
int map[1001][1001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m, x;
	cin >> n >> m >> x;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if ((i == j))
			{
				map[i][j] = 0;
				continue;
			}
			map[i][j] = INF;
		}
	}
	for (int i = 0; i < m; i++)
	{
		int from, to, cost;
		cin >> from >> to >> cost;
		map[from][to] = cost;
	}
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (i == j)
					continue;
				if (map[i][k] == INF || map[k][j] == INF)
				{
					continue;
				}
				map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		answer = max(answer, map[i][x] + map[x][i]);
	}
	cout << answer;
	return 0;
}
