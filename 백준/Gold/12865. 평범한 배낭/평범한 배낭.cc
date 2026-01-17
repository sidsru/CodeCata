// 백준
#include <iostream>
#define endl '\n'
using namespace std;

int n, k;
int DP[101][100001] = { 0 };

void Input()
{
	cin >> n >> k;
	for (int i = 1; i <= n; ++i)
	{
		int w, v;
		cin >> w >> v;
		for (int j = 0; j <= k; ++j)
		{
			if (j >= w)
			{
				DP[i][j] = DP[i - 1][j] > DP[i - 1][j - w] + v ?
					(DP[i - 1][j]) : (DP[i - 1][j - w] + v);
			}
			else
			{
				DP[i][j] = DP[i - 1][j];
			}
		}
	}
	cout << DP[n][k];
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	Input();
	return 0;
}
