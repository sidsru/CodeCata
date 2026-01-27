// 백준
#include <cstdio>
#define endl '\n'
using namespace std;
int arr[10001];
void findtree(const int start, const int end)
{
	if (start >= end)
		return;
	int i;
	for (i = start+1; i < end; ++i)
	{
		if (arr[start] < arr[i])
			break;
	}
	findtree(start+1, i);
	findtree(i, end);
    printf("%d\n", arr[start]);
}
void Input()
{
	int index = 0, i;
	while (scanf("%d", &i) != EOF)
	{
		arr[index++] = i;
	}
	findtree(0, index);
}
int main()
{
	Input();
	return 0;
}
