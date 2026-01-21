// 백준
#include <iostream>
#include <vector>
#define endl '\n'
using namespace std;

int arr[51];
vector<int> v[51];
int FindRoot(const int node)
{
	if (arr[node] == node)
	{
		return arr[node];
	}
	return arr[node] = FindRoot(arr[node]);
}
void UnionFind(const int a, const int b)
{
	int Anode = FindRoot(a);
	int Bnode = FindRoot(b);
	if (Anode != Bnode)
	{
		if (Anode > Bnode)
		{
			arr[Anode] = arr[Bnode];
		}
		else
		{
			arr[Bnode] = arr[Anode];
		}
	}
}
void Input()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
	{
		arr[i] = i;
	}
	int know;
	cin >> know;
	for (int i = 0; i < know; ++i)
	{
		int temp;
		cin >> temp;
		arr[temp] = 0;
	}
	for (int i = 0; i < m; ++i)
	{
		int cnt, temp;
		cin >> cnt;
		cin >> temp;
		v[i].push_back(temp);
		for (int j = 1; j < cnt; ++j)
		{
			int temp2;
			cin >> temp2;
			v[i].push_back(temp2);
			UnionFind(temp, temp2);
		}
	}
	int answer = m;
	for (int i = 0; i <m; ++i)
	{
		for (int j = 0; j < v[i].size(); ++j)
		{
			if (FindRoot(v[i][j]) == 0)
			{
				--answer;
				break;
			}
		}
	}
	cout << answer;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	Input();

	return 0;
}
