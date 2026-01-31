// 백준
#include <iostream>
#include <unordered_map>
#define endl '\n'
using namespace std;
constexpr int INF = (~0U >> 1);

int n, m, answer;
unordered_map<string, int> um;
void Input()
{
	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		string s;
		cin >> s;
		um.insert({ s, 0 });
	}
	for (int i = 0; i < m; ++i)
	{
		string s;
		cin >> s;
		if (um.find(s) != um.end())
			++answer;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	Input();
	cout << answer << endl;
	return 0;
}
