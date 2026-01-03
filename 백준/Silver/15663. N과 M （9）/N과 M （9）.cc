#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
vector<int> arr(10001);
bool visited[10001];
vector<int> v;
void DFS(const int depth)
{
	if (depth == m)
	{
		for (int a : v)
		{
			printf("%d ", a);
		}
		printf("\n");
		return;
	}
	int prev = 0;
	for (int i = 0; i < n; i++)
	{
		if (visited[i])
		{
			continue;
		}
		if (arr[i] == prev)
		{
			continue;
		}
		prev = arr[i];
		visited[i] = true;
		v.push_back(arr[i]);
		DFS(depth + 1);
		visited[i] = false;
		v.pop_back();
	}
}
int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &arr[i]);
	}
	sort(arr.begin(), arr.begin() + n);
	DFS(0);
}