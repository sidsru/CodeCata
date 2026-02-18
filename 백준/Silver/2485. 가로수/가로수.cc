// 백준
#include <iostream>
#define endl '\n'
using namespace std;
constexpr int INF = (~0U >> 1);
int GCD(const int a, const int b)
{
	if (b == 0)
		return a;
	return GCD(b, a % b);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	int arr[100001] = {};
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	int map[100001] = {};
	for (int i = 1; i < n; i++)
	{
		map[i - 1] = arr[i] - arr[i - 1];
	}
	int answer = map[0];
	for (int i = 1; i < n - 1; i++)
	{
		answer = GCD(map[i], answer);
	}
	int ans = 0;
	for (int i = 0; i < n - 1; i++)
	{
		ans += map[i] / answer - 1;
	}
	cout << ans;
	return 0;
}
