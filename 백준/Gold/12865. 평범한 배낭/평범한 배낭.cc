// 백준
#include <iostream>
#define endl '\n'
using namespace std;

int n, k;
int DP[100001] = { 0 };

void Input()
{
	cin >> n >> k;
	for (int i = 1; i <= n; ++i)
	{
		int w, v;
		cin >> w >> v;
		for (int j = k; j >= w; --j)
		{
			DP[j] = DP[j] > DP[j - w] + v ?
				(DP[j]) : (DP[j - w] + v);
		}
	}
	cout << DP[k];
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	Input();
	return 0;
}
