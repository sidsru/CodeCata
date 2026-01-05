#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
using namespace std;

int answer = -1;
int n, m;

void Greedy(const int start, const int target, const int depth)
{
	if (target >= start)
	{
		if (target > start)
		{
			return;
		}
		answer = depth;
		return;
	}
	if (start % 10 == 1)
	{

		Greedy(start / 10, target, depth + 1);
	}
	if (!(start & 1))
	{
		Greedy(start / 2, target, depth + 1);
	}
	return;
}
int main()
{
	scanf("%d %d", &n, &m);
	Greedy(m, n, 1);
	printf("%d", answer);
	return 0;
}