#include <stdio.h>

inline int Max(int a, int b)
{
    return a > b ? a : b;
}
int main()
{
    int answer=0, n, m, arr[101];
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; ++i)
        scanf("%d", &arr[i]);
    
    for(int i=0; i<n-2; ++i)
        for(int j=i+1; j<n-1; ++j)
            for(int k=j+1; k<n; ++k)
            {
                int sum = arr[i] + arr[j] + arr[k];
                if(sum<=m)
                    answer = Max(sum, answer);
            }
    printf("%d", answer);
}