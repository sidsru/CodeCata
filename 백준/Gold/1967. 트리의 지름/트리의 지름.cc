// 백준
#include <iostream>
#include <vector>
#include <string.h>
#define endl '\n'
using namespace std;
constexpr int INF = (~0U >> 1);

int n, Max, End;
vector<pair <int, int>> v[10001];
bool visited[10001];
void DFS(const int node, const int sum)
{
	if (visited[node])
	{
		return;
	}
	visited[node] = true;
	if (Max < sum)
	{
		Max = sum;
		End = node;
	}

	for (int i = 0; i < v[node].size(); ++i)
	{
		int nnode = v[node][i].first;
		int ncost = v[node][i].second;
		DFS(nnode, sum + ncost);
	}
}
void Input()
{
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		int from, to, cost;
		cin >> from >> to >> cost;
		v[from].push_back({ to, cost });
		v[to].push_back({ from, cost });
	}
	DFS(1, 0);
	memset(visited, false, sizeof(visited));
	DFS(End, 0);

}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	Input();
	cout << Max;
	return 0;
}
