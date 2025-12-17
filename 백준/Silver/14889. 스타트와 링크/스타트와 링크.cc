#include <stdio.h>
using namespace std;
int team[21][21];
int n, answer = 1000000000;
bool v[22] = {false, };
inline int ABS(int a) { return a > 0 ? a : -a; }
void teamset(int index, int count)
{
    if(count >= (n>>1))
    {
        int start = 0, link = 0;
        for(int i=1; i<=n; ++i)
            for(int j=1; j<=n; ++j)
            {
                if(v[i] && v[j])
                    start += team[i][j];
                
                else if(!v[i] && !v[j])
                    link += team[i][j];
            }
        int temp = ABS(start-link);
        if(temp < answer) 
            answer = temp;
        return;
    }
    for(int i=index;i<=n; ++i)
    {
        v[i] = true;
        teamset(i+1, count+1);
        v[i] = false;
    }
}
int main()
{
    scanf("%d", &n);
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=n; ++j)
            scanf("%d", &team[i][j]);
    teamset(1,0);
    printf("%d", answer);
}