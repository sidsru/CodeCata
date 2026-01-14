// 백준
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, answer = 0;
int edges[100001];
struct Edges
{
	int homea, homeb, cost;
	bool operator < (const Edges& other) const
	{
		return cost < other.cost;
	}
};


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
void kruskal(const vector<Edges>&  arr)
{
	int cnt = 0, answer = 0, max = 0;
	for (int i = 0; i < arr.size(); ++i)
	{
		int cost = arr[i].cost;
		int a = arr[i].homea;
		int b = arr[i].homeb;
		if (FindRoot(a) != FindRoot(b))
		{
			answer += cost;
			max = cost;
			unionfind(a, b);
			++cnt;
		}
		if (cnt == n - 1)
		{
			break;
		}
	}
	printf("%d", answer - max);
}
void input()
{
	cin >> n >> m;
	vector<Edges> arr(m);
	for (int i = 0; i < m; ++i)
	{
		cin >> arr[i].homea >> arr[i].homeb >> arr[i].cost;
	}
	sort(arr.begin(), arr.end());

	for (int i = 1; i <= n; ++i)
	{
		edges[i] = i;
	}
	kruskal(arr);
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	input();
	return 0;
}
