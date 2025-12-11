#include <stdio.h>

int main()
{
    int arr[2];
    float a = 0.22, n;
    scanf("%0f", &n);
    arr[0] = n - (n * a);
    arr[1] = n - ((n * 0.2) * a);
    printf("%d %d", arr[0],arr[1]);
}