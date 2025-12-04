#include <stdio.h>
#include <queue>
using namespace std;

int n,m;
int arr[1001][1001];

int movex[4] = {0, 0, 1, -1};
int movey[4] = {1, -1, 0, 0};
queue<pair<int, int>> q;
void BFS()
{
    while(!q.empty())
    {
        int x = q.front().second;
        int y = q.front().first;
        //printf("%d %d \n", y, x);
        
        q.pop();
        for(int i=0; i<4; ++i)
        {
            int nx = x + movex[i];
            int ny = y + movey[i];
            if(nx < 0 || ny < 0 || nx >= m || ny >= n)
                continue;
            if(arr[ny][nx] == 0)
            {
                arr[ny][nx] = arr[y][x] + 1;
                q.push({ny, nx});
                //printf("%d %d \n", ny, nx);
            }
        }
    }
}
int main()
{
    scanf("%d %d", &m, &n);
    for(int i=0; i<n; ++i)
        for(int j=0; j<m; ++j)
        {
            scanf("%d", &arr[i][j]);
            if(arr[i][j] == 1)
                q.push({i, j});
        }
    BFS();
    int result = 0;
    for(int i=0; i<n; ++i)
        for(int j=0; j<m; ++j)
        {
            if(arr[i][j] == 0)
            {
                printf("%d", -1);
                return 0;
            }
            if(result < arr[i][j])
                result = arr[i][j];
        }
    printf("%d", result - 1);
    return 0;
}