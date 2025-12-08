#include <stdio.h>
int arr[501][501];
int minblock = 256, maxblock = 0, time = 987654321, hres = 0;
int n, m;

inline int Min(const int& a, const int& b) { return a < b ? a : b; }
inline int Max(const int& a, const int& b) { return a > b ? a : b; }

void findblock(const int& h, int b)
{
    int ptime = 0;
    for(int i=0; i<n; ++i)
        for(int j=0; j<m; ++j)
            if(arr[i][j]>h)
            {
                ptime += (arr[i][j] - h) << 1;
                b += arr[i][j] - h;
            }
        
    for(int i=0; i<n; ++i)
        for(int j=0; j<m; ++j)
            if(arr[i][j] < h)
            {
                ptime += h - arr[i][j];
                b -= h - arr[i][j] ;
            }
    if(b>=0)
    {
        time = Min(time, ptime);
        if(time == ptime)
            hres = Max(hres, h);
    }
}

int main()
{
    int b;
    scanf("%d %d %d", &n, &m, &b);
    for(int i=0; i<n; ++i)
        for(int j=0; j<m; ++j)
        {
            scanf("%d", &arr[i][j]);
            minblock = Min(minblock, arr[i][j]);
            maxblock = Max(maxblock, arr[i][j]);
        }
    for(int i=minblock; i<=maxblock; ++i)
    {
        findblock(i,b);
    }
    printf("%d %d", time, hres);
}