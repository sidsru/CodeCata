#include <stdio.h>
#include <queue>
using namespace std;
int arr[1001][1001] = {0, };
bool b[1001][1001] = {false, };
int n ,m;

void BFS(int x, int y)
{
    int movex[4] = {0, 0, 1, -1};
    int movey[4] = {1, -1, 0, 0};
    int cnt = 0;
    arr[y][x] = cnt++;
    queue<pair<int,int>> q;
    q.push({x, y});
    while(!q.empty())
    {
        int qsize = q.size();
        for(int i=0; i<qsize; ++i)
        {
            int temp1 = q.front().first;
            int temp2 = q.front().second;
            q.pop();
            for(int i=0; i<4; ++i)
            {
                int newx = temp1 + movex[i];
                int newy = temp2 + movey[i];
                if(newx<0||newx>=m||newy<0||newy>=n)
                    continue;
                if(b[newy][newx])
                    continue;
                if(!arr[newy][newx])
                    continue;
                b[newy][newx] = true;
                arr[newy][newx] = cnt;
                q.push({newx, newy});
            } 
        }
        ++cnt;
    }
}
int main()
{
    int temp, x, y;
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; ++i)
        for(int j=0; j<m; ++j)
        {
            scanf("%d", &arr[i][j]);
            if(arr[i][j] == 2)
            {
                x = j; y = i;
            }
        }
    BFS(x, y);
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<m; ++j)
        {
            if(b[i][j])
                printf("%d ", arr[i][j]);
            else
            {
                if(!arr[i][j])
                    printf("0 ");
                else
                    printf("-1 ");
            }
        }
        printf("\n");
    }
}