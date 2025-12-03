#include <stdio.h>
#include <cmath>
using namespace std;
int n, answer = 0;
int arr[15];
bool check(int level)
{
    for(int i=0; i<level; ++i)
        if(arr[i] == arr[level] || abs(arr[level] - arr[i]) == level - i)
            return false;
    
    return true;
}

void nqueen(int x)
{
    if(n == x)
    {
        ++answer;
        return;
    }
    else
    {
        for(int i=0; i<n; ++i)
        {
            arr[x] = i;
            if(check(x))
                nqueen(x+1);
        }
    }
}

int main()
{
    scanf("%d", &n);
    nqueen(0);
    printf("%d", answer);
}