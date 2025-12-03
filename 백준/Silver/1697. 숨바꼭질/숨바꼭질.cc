#include <stdio.h>
#include <queue>
using namespace std;
bool b[100001] = {false, };
int BFS(const int& n, const int& k)
{
    queue<pair<int, int>> q;
    q.push({n,0});
    while(!q.empty())
    {
        int x = q.front().first;
        int cnt = q.front().second;
        q.pop();
        if(x == k)
            return cnt;
        if(0 <= x-1 && !b[x-1])
        {
            q.push({x-1, cnt+1});
            b[x-1] = true;
        }
            
        if(x+1 <= 100000 && !b[x+1])
        {
            q.push({x+1, cnt+1});
            b[x+1] = true;
        }
        if(x*2 <= 100000 && !b[x*2])
        {
            q.push({x*2, cnt+1});
            b[x*2] = true;
        }
    }
    return 0;
}
int main()
{
    int N, K;
    scanf("%d %d", &N, &K);
    printf("%d", BFS(N, K));
}