// 백준
#include <iostream>
#include <queue>
#define endl '\n'
using namespace std;
constexpr int INF = (~0U >> 1);

int n, m, start;
long long Value[20001];
void Dji(const vector<vector<pair<int, int>>>& v)
{
	for (int i = 1; i <= n; i++)
	{
		Value[i] = INF;
	}
	Value[start] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, start });

	while (!pq.empty())
	{
		int cost = pq.top().first;
		int now = pq.top().second;
		pq.pop();
		for (int i = 0; i < v[now].size(); ++i)
		{
			int ncost = v[now][i].first;
			int nnode = v[now][i].second;
			if (cost + ncost < Value[nnode])
			{
				Value[nnode] = cost + ncost;
				pq.push({ Value[nnode], nnode });
			}
		}
	}
}

void Input()
{
	cin >> n >> m;
	vector<vector<pair<int, int>>> v(n + 1);
	cin >> start;
	for (int i = 0; i < m; ++i)
	{
		int from, to, cost;
		cin >> from >> to >> cost;
		v[from].push_back({ cost, to });
	}
	Dji(v);
	for (int i = 1; i <= n; ++i)
	{
		if (Value[i] == INF)
		{
			cout << "INF" << endl;
		}
		else
		{
			cout << Value[i] << endl;
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	Input();

	return 0;
}
