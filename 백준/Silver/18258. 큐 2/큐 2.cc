// 백준
#include <iostream>
#include <queue>
#define endl '\n'
using namespace std;
constexpr int INF = (~0U >> 1);
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	queue<int> q;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		if (s == "push")
		{
			int temp;
			cin >> temp;
			q.push(temp);
		}
		else if (s == "pop")
		{
			if (q.empty() == true)
			{
				cout << -1 << endl;
				continue;
			}
			cout << q.front() << endl;
			q.pop();
		}
		else if (s == "size")
		{
			cout << q.size() << endl;
		}
		else if (s == "empty")
		{
			if (q.empty() == true)
			{
				cout << 1 << endl;
			}
			else if (q.empty() == false)
			{
				cout << 0 << endl;
			}
		}
		else if (s == "front")
		{
			if (q.empty() == true)
			{
				cout << -1 << endl;
				continue;
			}
			cout << q.front() << endl;
		}
		else if (s == "back")
		{
			if (q.empty() == true)
			{
				cout << -1 << endl;
				continue;
			}
			cout << q.back() << endl;
		}
	}
	return 0;
}
