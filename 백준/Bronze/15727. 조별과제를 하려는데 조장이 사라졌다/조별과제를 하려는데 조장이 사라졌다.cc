#include <stdio.h>

int main ()
{
    int l;
    scanf("%d", &l);
    int temp = l/5;
    if(l%5 != 0)
        ++temp;
    printf("%d", temp);
    return 0;
}