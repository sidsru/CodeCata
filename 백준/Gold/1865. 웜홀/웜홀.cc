// 백준
#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;
constexpr int INF = (~0U >> 1);
int n, m, w;
int Distance[501];
vector<pair<pair<int, int>, int>> Edge;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int tc;
	cin >> tc;
	for (int i = 0; i < tc; i++)
	{
		cin >> n >> m >> w;
		for (int j = 1; j <= n; j++)
		{
			Distance[i] = INF;
		}
		Edge.clear();
		for (int j = 0; j < m; j++)
		{
			int from, to, cost;
			cin >> from >> to >> cost;
			Edge.push_back({ {from, to}, cost });
			Edge.push_back({ { to, from }, cost });

		}
		for (int j = 0; j < w; j++)
		{
			int from, to, cost;
			cin >> from >> to >> cost;
			Edge.push_back({ {from, to}, -cost });

		}
		Distance[1] = 0;
		for (int j = 1; j < n; j++)
		{
			for (int k = 0; k < Edge.size(); k++)
			{
				int From = Edge[k].first.first;
				int To = Edge[k].first.second;
				int Cost = Edge[k].second;

				if (Distance[From] == INF)
					continue;
				if (Distance[To] > Distance[From] + Cost)
				{
					Distance[To] = Distance[From] + Cost;
				}
			}
		}
		string answer;
		for (int j = 0; j < Edge.size(); j++)
		{
			int From = Edge[j].first.first;
			int To = Edge[j].first.second;
			int Cost = Edge[j].second;

			if (Distance[From] == INF)
				continue;
			if (Distance[To] > Distance[From] + Cost)
			{
				answer = "YES";
				break;
			}
			answer = "NO";
		}
		cout << answer << endl;
	}
	return 0;
}
