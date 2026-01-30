// 백준
#include <iostream>
#define endl '\n'
using namespace std;
constexpr int INF = (~0U >> 1);

int n, answer;
int arr[1001];
int Updp[1001];
int Downdp[1001];

void Dp()
{
	for (int i = 1; i <= n; i++)
	{
		Updp[i] = 1;
		for (int j = 1; j < i; j++)
		{
			if (arr[i] > arr[j] && Updp[i] < Updp[j] + 1)
			{
				Updp[i] = Updp[j] + 1;
			}
		}
	}
	for (int i = n; i >= 1; i--)
	{
		Downdp[i] = 1;
		for (int j = n; j >= i; j--)
		{
			if (arr[i] > arr[j] && Downdp[i] < Downdp[j] + 1)
			{
				Downdp[i] = Downdp[j] + 1;
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (answer < Updp[i] + Downdp[i] - 1)
		{
			answer = Updp[i] + Downdp[i] - 1;
		}
	}
}
void Input()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	Dp();
	cout << answer << endl;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	Input();
	return 0;
}
