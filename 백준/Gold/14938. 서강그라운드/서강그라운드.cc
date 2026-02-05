// 백준
#include <iostream>
#define endl '\n'
using namespace std;
constexpr int INF = (~0U >> 1);

int n, m, r, node[101];
int map[101][101];
int answer = 0;

void Djikstra()
{

	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (i == j)
					continue;
				if (map[i][k] == INF || map[k][j] == INF)
					continue;
				if(map[i][j]> map[i][k] + map[k][j])
				{
					map[i][j] = map[i][k] + map[k][j];
				}
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		int temp = 0;
		for (int j = 1; j <= n; j++)
		{
			if (map[i][j] <= m)
			{
				temp += node[j];
			}
		}
		answer = max(answer, temp);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m >> r;
	for (int i = 1; i <= n; i++)
	{
		cin >> node[i];
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j)
			{
				map[i][j] = 0;
			}
			else
			{
				map[i][j] = INF;
			}
		}
	}
	for (int i = 0; i < r; i++)
	{
		int from, to, cost;
		cin >> from >> to >> cost;
		map[from][to] = cost;
		map[to][from] = cost;
	}
	Djikstra();

	cout << answer << endl;
	return 0;
}
