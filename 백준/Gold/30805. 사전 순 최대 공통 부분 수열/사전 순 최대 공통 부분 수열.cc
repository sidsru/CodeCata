// 백준
#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;
constexpr int INF = (~0U >> 1);
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n;
	vector<int> arrA(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arrA[i];
	}
	cin >> m;
	vector<int> arrB(m);
	for (int i = 0; i < m; i++)
	{
		cin >> arrB[i];
	}
	bool flag = true;
	vector<int> answer;
	while (true)
	{
		int AMaxElement, AMaxIndex, BMaxElement, BMaxIndex;
		while (true)
		{
			if (arrA.size() == 0 || arrB.size() == 0)
			{
				flag = false;
				break;
			}
			AMaxElement = *max_element(arrA.begin(), arrA.end());
			AMaxIndex = max_element(arrA.begin(), arrA.end()) - arrA.begin();
			BMaxElement = *max_element(arrB.begin(), arrB.end());
			BMaxIndex = max_element(arrB.begin(), arrB.end()) - arrB.begin();
			if (AMaxElement == BMaxElement)
			{
				break;
			}
			else if (AMaxElement > BMaxElement)
			{
				arrA.erase(arrA.begin() + AMaxIndex);
			}
			else if (AMaxElement < BMaxElement)
			{
				arrB.erase(arrB.begin() + BMaxIndex);
			}
		}
		if (flag == false)
		{
			break;
		}
		answer.push_back(AMaxElement);
		int temp = 0;
		for (int i = AMaxIndex+1; i < arrA.size(); i++)
		{
			arrA[temp] = arrA[i];
			++temp;
		}
		for (int i = 0; i <= AMaxIndex; i++)
		{
			arrA.pop_back();
		}
		temp = 0;
		for (int i = BMaxIndex+1; i < arrB.size(); i++)
		{
			arrB[temp] = arrB[i];
			++temp;
		}
		for (int i = 0; i <= BMaxIndex; i++)
		{
			arrB.pop_back();
		}
	}
	if (!answer.empty())
	{
		cout << answer.size() << endl;
		for (int ans : answer)
		{
			cout << ans << ' ';
		}
	}
	else
	{
		cout << 0;
	}
	return 0;
}
