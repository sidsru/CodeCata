#include <stdio.h>
#include <vector>
using namespace std;
int arr[100001] = { 0, };
bool visited[100001] = { false, };
vector<int> v[100001];

void DFS(const int now)
{
	for (int i = 0; i < v[now].size(); ++i)
	{
		int next = v[now][i];
		if (visited[next])
		{
			continue;
		}
		visited[next] = true;
		arr[next] = now;
		DFS(next);
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
	DFS(1);
	for (int i = 2; i <=n; ++i)
	{
		printf("%d\n", arr[i]);
	}
	return 0;
}