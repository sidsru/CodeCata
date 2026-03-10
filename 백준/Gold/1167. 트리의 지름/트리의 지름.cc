// 백준
#include <iostream>
#include <vector>
#include <cstring>
#define endl '\n'
using namespace std;
constexpr int INF = (~0U >> 1);

vector<pair<int, int>> v[100001];
int selectnode, dist;
bool visited[100001];

void DFS(const int start, const int cnt)
{
	if (cnt > dist)
	{
		dist = cnt;
		selectnode = start;
	}

	for (pair<int, int> node : v[start])
	{
		int n = node.first;
		int cost = node.second;
		if (visited[n] == true)
			continue;
		visited[n] = true;
		DFS(n, cnt + cost);
		visited[n] = false;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int from, to, cost;
		cin >> from;
		while (true)
		{
			cin >> to;
			if (to == -1)
				break;
			cin >> cost;
			v[from].push_back(make_pair(to, cost));
		}
	}
	visited[1] = true;
	DFS(1, 0);
	memset(visited, false, sizeof(visited));
	dist = 0;
	visited[selectnode] = true;
	DFS(selectnode, 0);
	cout << dist;
	return 0;
}
