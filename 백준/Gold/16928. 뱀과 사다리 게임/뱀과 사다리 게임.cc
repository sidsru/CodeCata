#include <stdio.h>
#include <queue>
using namespace std;
int arr[101];
bool visible[101] = {false, };
int BFS()
{
    queue<pair<int,int>> q;
    q.push({1, 0});
    visible[1] = true;
    while(!q.empty())
    {
        int temp = q.front().first;
        int cnt = q.front().second;
        q.pop();
        for(int i=1; i<=6; ++i)
        {
            if(temp + i >=100)
            {
                if(temp + i == 100)
                    return cnt+1;
                continue;
            }
            if(visible[temp+i])
                continue;
            
            q.push({arr[temp+i], cnt+1});
            visible[temp+i] = true;
        }
    }
    return -1;
}
 int main()
 {
     for(int i=1; i<=100; ++i)
         arr[i] = i;
     int n, m;
     scanf("%d %d", &n, &m);
     for(int i = 0; i<n+m; ++i)
     {
         int temp1, temp2;
         scanf("%d %d", &temp1, &temp2);
         arr[temp1] = temp2;
     }
     printf("%d", BFS());
 }