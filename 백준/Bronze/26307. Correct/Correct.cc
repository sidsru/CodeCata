#include <stdio.h>

int main()
{
    int h, m;
    scanf("%d %d", &h, &m);
    int answer = ((h-9) * 60) + m;
    printf("%d",answer);
}