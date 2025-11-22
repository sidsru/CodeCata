#include <iostream>
#include <algorithm>
using namespace std;

int m, n;
int arr[50][50];
int xpos[4] = {0, 0, -1, 1};
int ypos[4] = {-1, 1, 0, 0};

void DFS(int x, int y)
{
    arr[x][y] = 0;
    for(int i=0; i<4; i++)
    {
        int xx = x + xpos[i];
        int yy = y + ypos[i];
        if( xx < 0 || yy < 0 || xx >= m || yy >= n)
        {
            continue;
        }
        if(arr[xx][yy] == 1)
            DFS(xx, yy);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    for(int i=0; i<t;i++)
    {
        int k, answer = 0;
        cin >> m >> n >> k;
        for(int j=0; j<k; j++)
        {
            int x, y;
            cin >> x >> y;
            arr[x][y] = 1;
        }
        
        for(int j = 0; j < m; j++)
            for(int l = 0; l < n; l++)
                if(arr[j][l] == 1)
                {
                    DFS(j,l);
                    answer++;
                }
        
        cout << answer << '\n';
    }
    return 0;
}