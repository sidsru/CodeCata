#include <stdio.h>
#include <queue>
#include <cstring>
using namespace std;
int xmove[4] = {0,0,1,-1};
int ymove[4] = {1,-1,0,0};
int n;
char RGB[101][101];
bool visible[101][101] = {false, };
int color[2] = {0,0};
inline bool check(const int x, const int y)
{
    return (x<0 || y<0 || n<=x || n<=y);
}

void BFS(const int x, const int y)
{
    queue<pair<int,int>> q;
    q.push({x,y});
    const char target = RGB[x][y];
    visible[x][y] = true;
    while(!q.empty())
    {
        int xtemp = q.front().first;
        int ytemp = q.front().second;
        q.pop();
        for(int i=0; i<4; ++i)
        {
            int xx = xtemp + xmove[i];
            int yy = ytemp + ymove[i];
            if(check(xx, yy) || visible[xx][yy])
                continue;
            if(RGB[xx][yy] != target)
                continue;
            q.push({xx,yy});
            visible[xx][yy] = true;
        }
    }
}
int main()
{
    scanf("%d", &n);
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<n; ++j)
            scanf(" %c", &RGB[i][j]);
        //getchar();
    }
       
    for(int i=0; i<n; ++i)
        for(int j=0; j<n; ++j)
            if(!visible[i][j])
            {
                BFS(i,j);
                ++color[0];
            }
        
    for(int i=0; i<n; ++i)
        for(int j=0; j<n; ++j)
            if(RGB[i][j] == 'G')
                RGB[i][j] = 'R';
    //fill(&visible[0][0], &visible[101][101], false);
    memset(visible, false, sizeof(visible));
    for(int i=0; i<n; ++i)
        for(int j=0; j<n; ++j)
            if(!visible[i][j])
            {
                BFS(i,j);
                ++color[1];
            }
    printf("%d %d", color[0], color[1]);
}