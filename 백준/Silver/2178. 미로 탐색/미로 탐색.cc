#include <iostream>
#include <queue>
using namespace std;
bool map[101][101] = {false, };
int BFS(const int& n, const int& m)
{
    bool visible[101][101] = {false, };
    int xmove[4] = {0,0,1,-1};
    int ymove[4] = {1,-1,0,0};
    queue<pair<pair<int,int>,int>> q;
    q.push({{0,0},1});
    visible[0][0] = false;
    while(!q.empty())
    {
        pair<int, int>xy = q.front().first;
        int cnt = q.front().second;
        q.pop();
        for(int i=0; i<4; ++i)
        {
            int xx = xy.first + xmove[i];
            int yy = xy.second + ymove[i];
            if(xx < 0 || yy < 0 || n <=xx || m <= yy)
                continue;
            if(!map[xx][yy] || visible[xx][yy])
                continue;
            if(xx == n-1 && yy == m-1)
                return cnt+1;
            q.push({{xx,yy}, cnt+1});
            visible[xx][yy] = true;
        }
    }
    return 0;
}
int main ()
{

    int n,m;
    cin >> n >> m;
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<m; ++j)
        {
            char Load;
            cin >> Load;
            map[i][j] = (Load == '1');
        }
    }
    cout << BFS(n,m);
}