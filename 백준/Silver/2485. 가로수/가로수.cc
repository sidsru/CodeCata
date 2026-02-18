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
	int answer = arr[1] - arr[0];
	for (int i = 2; i < n; i++)
	{
		answer = GCD(arr[i] - arr[i - 1] , answer);
	}
	int dist = arr[n - 1] - arr[0];

	cout << (dist/answer) + 1 - n;
	return 0;
}
