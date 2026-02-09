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
	string s;
	cin >> s;
	unordered_map<string, int> um;
	for (int i = 0; i < s.size(); i++)
	{
		for (int j = 1; j <= s.size(); j++)
		{
			um[s.substr(i,j)]++;
		}
	}

	int answer = 0;
	for (unordered_map<string, int>::iterator it = um.begin(); it != um.end(); it++)
	{
		answer++;
	}
	cout << answer;
	return 0;
}
