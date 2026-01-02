#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
int arr[100001] = { 0, };
vector<int> v[100001];
bool visited[100001] = { false, };
void BFS()
{
	queue<int> q;
	q.push(1);
	visited[1] = false;
	while (!q.empty())
	{
		int node = q.front();
		q.pop();
		for (int i = 0; i < v[node].size(); ++i)
		{
			int next = v[node][i];
			if (visited[next])
			{
				continue;
			}
			visited[next] = true;
			arr[next] = node;
			q.push(next);
		}
	}
	return;
}
int main()
{
	int n;
	scanf("%d", &n);
	
	for (int i = 0; i < n; ++i)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	BFS();
	for (int i = 2; i <=n; ++i)
	{
		printf("%d\n", arr[i]);
	}
	return 0;
}