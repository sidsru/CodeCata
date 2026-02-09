// 백준
#include <iostream>
#include <unordered_set>
#define endl '\n'
using namespace std;
constexpr int INF = (~0U >> 1);
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	string s;
	cin >> s;
	unordered_set<string> st;
	for (int i = 0; i < s.size(); i++)
	{
		for (int j = 1; j <= s.size()-i; j++)
		{
			st.insert(s.substr(i, j));
		}
	}

	cout << st.size();
	return 0;
}
