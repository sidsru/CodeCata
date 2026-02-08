// 백준
#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;
constexpr int INF = (~0U >> 1);
bool BinarySearch(const vector<int>& v, const int target)
{
	int start = 0;
	int end = v.size() - 1;
	while (start <= end)
	{
		int mid = (start + end) / 2;
		if (v[mid] == target)
		{
			return true;
		}

		if (v[mid] < target)
		{
			start = mid + 1;
		}
		else
		{
			end = mid - 1;
		}
	}
	return false;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(m);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	for (int i = 0; i < m; i++)
	{
		cin >> b[i];
	}
	sort(b.begin(), b.end());
	int answer = a.size()+ b.size();
	for (int temp : a)
	{
		if (BinarySearch(b, temp))
		{
			--answer;
			--answer;
		}
	}
	cout << answer;
	return 0;
}
