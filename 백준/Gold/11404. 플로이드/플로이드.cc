// 백준
#include <iostream>
#define endl '\n'
using namespace std;
constexpr int INF = (~0U >> 1);

int n, m;
int arr[101][101];
void Input()
{
	cin >> n;
	cin >> m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			arr[i][j] = INF;
		}
	}
	for (int i = 0; i < m; i++)
	{
		int from, to, cost;
		cin >> from >> to >> cost;
		arr[from][to] = arr[from][to] > cost ? cost : arr[from][to];

	}
	for (int i = 1; i <= n; i++)
	{
		arr[i][i] = 0;
	}
	for (int mid = 1; mid <= n; mid++)
	{
		for (int from = 1; from <= n; from++)
		{
			for (int to = 1; to <= n; to++)
			{
				if (arr[from][mid] == INF || arr[mid][to] == INF)
					continue;
				if (arr[from][to] > arr[from][mid] + arr[mid][to])
				{
					arr[from][to] = arr[from][mid] + arr[mid][to];
				}
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (arr[i][j] == INF)
			{
				cout << 0 << ' ';
			}
			else
			{
				cout << arr[i][j] << ' ';
			}
		}
		cout << endl;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	Input();
	return 0;
}
