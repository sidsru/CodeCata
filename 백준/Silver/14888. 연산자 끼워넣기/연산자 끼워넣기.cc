#include <stdio.h>
long long arr[11];
int n;
long long Maxnum = -1000000001, Minnum = 1000000001;
int math[4];
inline int Min(int a, int b){return a < b ? a : b;}
inline int Max(int a, int b){return a > b ? a : b;}
void getanswer(int index, int num)
{
    if(index == n)
    {
        Maxnum = Max(Maxnum, num);
        Minnum = Min(Minnum, num);
        return;
    }
    for(int i=0; i<4; ++i)
    {
        if(math[i]>0)
        {
            --math[i];
            switch(i)
            {
                case 0:
                    getanswer(index+1, num+arr[index]);
                    break;
                case 1:
                    getanswer(index+1, num-arr[index]);
                    break;
                case 2:
                    getanswer(index+1, num*arr[index]);
                    break;
                case 3:
                    getanswer(index+1, num/arr[index]);
                    break;
            }
            ++math[i];
        }
    }
}
int main()
{
    scanf("%d", &n);
    for(int i=0; i<n; ++i)
        scanf("%d", &arr[i]);
    
    for(int i=0; i<4;++i)
        scanf("%d", &math[i]);
    getanswer(1, arr[0]);
    printf("%d\n%d", Maxnum, Minnum);
}