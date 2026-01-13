// 프로그레머스
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <string>
#include <vector>
#define INF ~0ULL >> 1
using namespace std;

long long dist(const long long x, const long long y, const long long startx, const long long starty)
{
	long long dx = startx - x;
	long long dy = starty - y;
	return dx * dx + dy * dy;
}
vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls)
{
	vector<int> answer;
	for (vector<int> ball : balls)
	{
		long long x = ball[0];
		long long y = ball[1];
		long long min = INF;
		if (!(x == startX && y > startY))
		{
			long long up = dist(x, (n << 1) - y, startX, startY);
			if (up < min)
			{
				min = up;
			}
		}
		if (!(x == startX && y < startY))
		{
			long long down = dist(x, -y, startX, startY);
			if (down < min)
			{
				min = down;
			}
		}
		if (!(y == startY && x < startX))
		{
			long long left = dist(-x, y, startX, startY);
			if (left < min)
			{
				min = left;
			}
		}
		if (!(y == startY && x > startX))
		{
			long long right = dist((m << 1) - x, y, startX, startY);
			if (right < min)
			{
				min = right;
			}
		}
		answer.push_back(min);
	}
	return answer;
}
