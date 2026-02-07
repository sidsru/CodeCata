// 백준
#include <iostream>
#include <map>
#define endl '\n'
using namespace std;
constexpr int INF = (~0U >> 1);
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	map<string, bool, greater<string>> um;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string name, status;
		cin >> name >> status;
		if (status == "enter")
		{
			um[name] = true;
		}
		if (status == "leave")
		{
			if (um.find(name) != um.end())
			{
				um[name] = false;
			}
		}
	}
	for (map<string, bool>::iterator it = um.begin(); it != um.end(); it++)
	{
		if (it->second == true)
		{
			cout << it->first << endl;
		}
	}
	return 0;
}
