#include <stdio.h>
#include <queue>
using namespace std;
int tomatobox[101][101][101];
int m, n, h; // h == z == i, m == x == j, n == y == k
int xmove[6] = {0,0,0,0,1,-1};
int ymove[6] = {0,0,1,-1,0,0};
int zmove[6] = {1,-1,0,0,0,0};
queue<pair<pair<int, int>,pair<int, int>>> q;
bool check(const int x, const int y, const int z)
{
    return (x < 0|| y < 0 || z < 0 || h<=z || m<=x || n<=y);
}
int BFS()
{
    int cnt = 0;
    while(!q.empty())
    {
        int z = q.front().first.first;
        int y = q.front().first.second;
        int x = q.front().second.first;
        cnt = q.front().second.second;
        q.pop();
        for(int i=0;i<6; ++i)
        {
            int xx = x + xmove[i];
            int yy = y + ymove[i];
            int zz = z + zmove[i];
            if(check(xx, yy, zz))
                continue;
            if(tomatobox[zz][yy][xx] != 0)
                continue;
            q.push({{zz,yy},{xx, cnt+1}});
            tomatobox[zz][yy][xx] = 1;
        }
    }
    for(int i=0; i<h; ++i)
        for(int j=0; j<n; ++j)
            for(int k=0; k<m; ++k)
                if(tomatobox[i][j][k] == 0)
                    return -1;
    return cnt;
}

int main()
{
    scanf("%d %d %d", &m, &n, &h);
    
    for(int i=0; i<h; ++i)
        for(int j=0; j<n; ++j)
            for(int k=0; k<m; ++k)
            {
                scanf("%d", &tomatobox[i][j][k]);
                if(tomatobox[i][j][k] == 1)
                    q.push({{i,j},{k,0}});
            }
    printf("%d", BFS());
}