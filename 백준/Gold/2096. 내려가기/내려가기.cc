// 백준
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
using namespace std;

inline int min(const int a, const int b)
{
	return a > b ? b : a;
}
inline int max(const int a, const int b)
{
	return a > b ? a : b;
}
int DP[3];
int DPMax[3];
int DPMin[3];
void input()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d %d %d", &DP[0], &DP[1], &DP[2]);

		int temp0 = DPMax[0], temp1 = DPMax[1], temp2 = DPMax[2];

		DPMax[0] = max(temp0, temp1) + DP[0];
		DPMax[1] = max(max(temp1, temp2), temp0) + DP[1];
		DPMax[2] = max(temp2, temp1) + DP[2];

		temp0 = DPMin[0], temp1 = DPMin[1], temp2 = DPMin[2];

		DPMin[0] = min(temp0, temp1) + DP[0];
		DPMin[1] = min(min(temp1, temp2), temp0) + DP[1];
		DPMin[2] = min(temp2, temp1) + DP[2];
	}
	int maxvalue = max(DPMax[0], max(DPMax[1], DPMax[2]));
	int minvalue = min(DPMin[0], min(DPMin[1], DPMin[2]));
	printf("%d %d", maxvalue, minvalue);
}

int main()
{
	input();

	return 0;
}
