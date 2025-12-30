#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> v;
vector<int> answer;
bool visited[9];

void DFS(const int depth)
{
	if (m == depth)
	{
		for (int ans : answer)
		{
			printf("%d ", ans);

		}
		printf("\n");
		return;
	}
	else
	{
		for (int i = 0; i < n; ++i)
		{
			if (visited[i])
			{
				continue;
			}
			visited[i] = true;
			answer.push_back(v[i]);
			DFS(depth + 1);
			visited[i] = false;
			answer.pop_back();
		}
	}
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i)
	{
		int temp;
		scanf("%d", &temp);
		v.push_back(temp);
	}
	sort(v.begin(), v.end());
	DFS(0);
	return 0;
}