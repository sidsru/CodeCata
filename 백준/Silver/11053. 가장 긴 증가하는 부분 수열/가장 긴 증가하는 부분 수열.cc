#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>	
#include <vector>
using namespace std;
int arr[1000];
int n;
int BinarySearch(const vector<int>& v, int start, int end, const int num)
{
	while (start < end)
	{
		int mid = (start + end) / 2;
		if (num > v[mid])
		{
			start = mid + 1;
		}
		else
		{
			end = mid;
		}
	}
	return end;
}

int DP()
{
	vector<int> v;
	v.push_back(arr[0]);
	for (int i = 1; i < n; ++i)
	{
		if (arr[i] > v.back())
		{
			v.push_back(arr[i]);
		}
		else
		{
			int pos = BinarySearch(v, 0, v.size() - 1, arr[i]);
			v[pos] = arr[i];
		}
	}
	return v.size();
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &arr[i]);

	}
	int answer = DP();
	printf("%d", answer);
	return 0;
}