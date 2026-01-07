#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
using namespace std;
int pow(long long a, long long b, long long c)
{
	if (b == 0)
	{
		return 1;
	}
	long long temp = pow(a, b / 2, c);
	temp = (temp * temp) % c;
	if (b & 1)
	{
		temp = (temp * a) % c;
	}
	return temp;
}
int main()
{
	long long a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	a = pow(a, b, c);
	printf("%d\n", a % c);
	return 0;
}
