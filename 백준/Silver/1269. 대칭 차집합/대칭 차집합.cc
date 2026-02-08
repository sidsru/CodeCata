// 백준
#include <iostream>
#include <unordered_map>
#define endl '\n'
using namespace std;
constexpr int INF = (~0U >> 1);
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	unordered_map<int, int> um;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n+m; i++)
	{
		int temp;
		cin >> temp;
		um[temp]++;

	}
	int answer = 0;
	for (unordered_map<int, int>::iterator it = um.begin(); it != um.end(); it++)
	{
		if (it->second & 1)
		{
			answer++;
		}
	}
	cout << answer;
	return 0;
}
