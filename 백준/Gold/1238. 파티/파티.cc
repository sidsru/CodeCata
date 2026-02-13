// 백준
#include <iostream>
#include <queue>
#define endl '\n'
using namespace std;
constexpr int INF = (~0U >> 1);
int n, m, x;
int Distance[1001];
int TotalDistance[1001];
int map[1001][1001];
void dijkstra(const int start)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	for (int i = 1; i <= n; i++)
	{
		Distance[i] = INF;
	}
	Distance[start] = 0;
	pq.push({ 0, start });
	while (!pq.empty())
	{
		int Dis = pq.top().first;
		int value = pq.top().second;
		pq.pop();
		for (int i = 1; i <= n; i++)
		{
			if (map[value][i] == 0)
				continue;
			if (Dis + map[value][i] < Distance[i])
			{
				Distance[i] = Dis + map[value][i];
				pq.push({ Distance[i],i });
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		TotalDistance[i] += Distance[i];
	}
}
void dijkstraRevers(const int start)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	for (int i = 1; i <= n; i++)
	{
		Distance[i] = INF;
	}
	Distance[start] = 0;
	pq.push({ 0, start });
	while (!pq.empty())
	{
		int Dis = pq.top().first;
		int value = pq.top().second;
		pq.pop();
		if (Dis > Distance[value])
			continue;
		for (int i = 1; i <= n; i++)
		{
			if (map[i][value] == 0)
				continue;
			if (Dis + map[i][value] < Distance[i])
			{
				Distance[i] = Dis + map[i][value];
				pq.push({ Distance[i], i });
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		TotalDistance[i] += Distance[i];
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m >> x;
	for (int i = 0; i < m; i++)
	{
		int from, to, cost;
		cin >> from >> to >> cost;
		map[from][to] = cost;
	}
	dijkstra(x);
	dijkstraRevers(x);

	int answer = 0;
	for (int i = 1; i <= n; i++)
	{
		answer = max(answer, TotalDistance[i]);
	}
	cout << answer;
	return 0;
}
