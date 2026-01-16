// 백준
#include <iostream>

using namespace std;
string a, b;
int dp[1001][1001];
inline int Max(const int a, const int b)
{
	return a > b ? a : b;
}
void DP()
{
	for (int i = 1; i < a.size(); ++i)
	{
		for (int j = 1; j < b.size(); ++j)
		{
			if (a[i] == b[j])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else
			{
				dp[i][j] = Max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	cout << dp[a.size()-1][b.size()-1];
}
void Input()
{
	cin >> a >> b;
	a = "0" + a;
	b = "0" + b;
	DP();
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	Input();
	return 0;
}
