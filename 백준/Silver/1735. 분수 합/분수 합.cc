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
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int e, f;
	e = (a * d + b * c);
	f = b * d;
	int g = GCD(e, f);
	cout << e / g << " " << f / g;
	return 0;
}
