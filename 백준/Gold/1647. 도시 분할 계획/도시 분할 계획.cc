// 백준
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, answer = 0;
int edges[100001];
vector<pair<int,pair<int, int>>> arr;


int FindRoot(const int a)
{
	if (a == edges[a])
	{
		return a;
	}
	return edges[a] = FindRoot(edges[a]);
}

void unionfind(const int a, const int b)
{
	int roota = FindRoot(a);
	int rootb = FindRoot(b);
	if (roota != rootb)
	{
		edges[roota] = rootb;
	}
	return;

}
void kruskal()
{
	int cnt = 0;
    vector<int> res;
	for (int i = 0;i<arr.size(); ++i)
	{
		int cost = arr[i].first;
		int a = arr[i].second.first;
		int b = arr[i].second.second;
		if (FindRoot(a) != FindRoot(b))
		{
			unionfind(a, b);
			++cnt;
            res.push_back(cost);
		}
		if (cnt == n - 1)
		{
			break;
		}
	}
    for(int i=0; i<res.size()-1; ++i)
    {
        answer += res[i];
    }
}
void input()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; ++i)
	{
		int homea, homeb, cost;
		scanf("%d %d %d", &homea, &homeb, &cost);
		arr.push_back({ cost,{homea, homeb} });
	}
	sort(arr.begin(), arr.end());

	for (int i = 1; i <= n; ++i)
	{
		edges[i] = i;
	}
	return;
}

int main()
{
	input();
	kruskal();
	printf("%d", answer);
	return 0;
}
