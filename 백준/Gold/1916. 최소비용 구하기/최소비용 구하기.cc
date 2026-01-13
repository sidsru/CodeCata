// 백준
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
#define INF ~0U>>1
using namespace std;

int n, m;
int totalcost[1001];
int bus[1001][1001];

void Dijkstra(const int start, const int end)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	totalcost[start] = 0;
	pq.push({ totalcost[start] ,start });
	while (!pq.empty())
	{
		int cost = pq.top().first;
		int node = pq.top().second;
		pq.pop();
		for (int nextnode = 1; nextnode <= n; ++nextnode)
		{
			if (bus[node][nextnode] == INF)
			{
				continue;
			}
			if (cost + bus[node][nextnode] < totalcost[nextnode])
			{
				totalcost[nextnode] = cost + bus[node][nextnode];
				pq.push({ totalcost[nextnode] , nextnode });
			}
		}
	}
	printf("%d", totalcost[end]);
}

void input()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i)
	{
		totalcost[i] = INF;
		for (int j = 1; j <= n; ++j)
		{
			bus[i][j] = INF;
		}
	}
	for (int i = 0; i < m; ++i)
	{
		int from, to, cost;
		scanf("%d %d %d", &from, &to, &cost);
		if (bus[from][to] > cost)
		{
			bus[from][to] = cost;
		}
	}
	int start, end;
	scanf("%d %d", &start, &end);
	Dijkstra(start, end);
}

int main()
{
	input();

	return 0;
}
