#include <stdio.h>

inline int pow(int n)
{
    int temp = 1;
    for(int i=0; i<n; ++i)
        temp *= 2;
    //printf("%d", temp);
    return temp;
}
int r, c, answer = 0;
void findz(int x, int y, int size)
{
    if(y == r && x == c)
    {
        printf("%d", answer);
        return;
    }
    else if(x<=c && y <= r && c < x+size && r < y+size)
    {
        findz(x, y, size/2);
        findz(x+size/2, y, size/2);
        findz(x, y+size/2, size/2);
        findz(x+size/2, y+size/2, size/2);
    }
    else
        answer += size * size;
}
int main()
{
    int n;
    scanf("%d %d %d", &n, &r, &c);
    findz(0, 0, pow(n));
}