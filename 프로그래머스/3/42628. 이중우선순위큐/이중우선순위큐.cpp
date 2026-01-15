// 프로그레머스
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
inline int ToIntiger(const string& s)
{
	return stoi(s.substr(2));
}
vector<int> solution(vector<string> operations) {
	vector<int> answer;
	int startidx = 0, endidx = 0;
	int arr[1000001];
	for (string& operation : operations)
	{
		char trigger = operation[0];
		int num = ToIntiger(operation);
		if (trigger == 'I')
		{
			arr[endidx] = num;
			++endidx;
			sort(&arr[startidx], &arr[endidx]);
		}
		if (trigger == 'D')
		{
			if (startidx >= endidx)
			{
				continue;
			}
			if (num == -1)
			{
				++startidx;
			}
			if (num == 1)
			{
				--endidx;
			}
		}
	}
	if (startidx >= endidx)
	{
		answer.push_back(0);
		answer.push_back(0);
		return answer;
	}
	answer.push_back(arr[endidx-1]);
	answer.push_back(arr[startidx]);
	return answer;
}
