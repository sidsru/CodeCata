// 백준
#include <iostream>
#define endl '\n'
using namespace std;
//constexpr int INF = (~0U >> 1);

long long MOD = 1'000'000'007;
long long gcd(long long a, long long b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}
long long f(long long x, long long y)
{
	if (y == 1)
		return x;
	if (y % 2 == 1)
		return x * f(x, y - 1) % MOD;
	long long half = f(x, y / 2);
	return half * half % MOD;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	long long m, answer = 0;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		long long a, b;
		cin >> b >> a;
		long long g = gcd(a, b);
		a /= g;
		b /= g;
		answer += a * f(b, MOD - 2) % MOD;
		answer %= MOD;
	}
	cout << answer << endl;
	return 0;
}
