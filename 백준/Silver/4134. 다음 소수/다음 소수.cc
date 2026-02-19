// 백준
#include <iostream>
#include <cmath>
#include <cstring>
#define endl '\n'
using namespace std;
constexpr int INF = (~0U >> 1);

bool Pirme(const long long n)
{
	if (n <= 1)
		return false;
	if (n == 2 || n == 3)
		return true;
	if (n % 2 == 0 || n % 3 == 0)
		return false;
	for (long long i = 5; i * i <= n; i += 6)
	{
		if (n % i == 0 || n % (i + 2) == 0)
			return false;
	}
	return true;
}
long long findPirme(long long start)
{
	while (true)
	{

		if (Pirme(start) == true)
			return start;

		++start;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		long long temp;
		cin >> temp;
		cout << findPirme(temp) << endl;
	}
	return 0;
}
