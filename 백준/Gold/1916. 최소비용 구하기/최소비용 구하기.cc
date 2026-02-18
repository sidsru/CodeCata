// 백준
#include <iostream>
#include <cstring>
#include <queue>
#define endl '\n'
using namespace std;
constexpr int INF = (~0U >> 1);
int n, m;
int map[1001];
vector<pair<int, int>> v[1001];
void Dijkstra(const int start, const int end)
{
	for (int i = 1; i <= n; i++)
	{
		map[i] = INF;
	}
	queue<pair<int, int>> q;
	q.push(make_pair(start, 0));
	map[start] = 0;
	while (q.empty() == false)
	{
		int now = q.front().first;
		int cost = q.front().second;
		q.pop();
		if (cost > map[now])
		{
			continue;
		}
		for (int i = 0; i < v[now].size(); i++)
		{
			int next = v[now][i].first;
			int ncost = v[now][i].second;
			if (ncost + cost < map[next])
			{
				map[next] = ncost + cost;
				q.push(make_pair(next, map[next]));
			}
		}
	}
	cout << map[end];
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int from, to, cost;
		cin >> from >> to >> cost;
		v[from].push_back(make_pair(to, cost));
	}

	int start, end;
	cin >> start >> end;
	Dijkstra(start, end);
	return 0;
}
