#include <iostream>
#include <queue>
using namespace std;
int xmove[4] = {0, 0, 1, -1};
int ymove[4] = {1, -1, 0, 0};
bool vis[601][601] = {false, };
string s[601];
int answer = 0, n ,m;

void BFS(const int x, const int y)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0; i<4; ++i)
        {
            int xx = x + xmove[i];
            int yy = y + ymove[i];
            if(xx >= n || yy >= m || xx < 0 || yy < 0)
                continue;
            if(vis[xx][yy] || s[xx][yy] == 'X')
                continue;
            q.push({xx, yy});
            vis[xx][yy] = true;
            if(s[xx][yy] == 'P')
                ++answer;
        }
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int ix = -1, iy = -1;
    cin >> n >> m;
    for(int i=0; i<n; ++i)
    {
        cin >> s[i];
        if(ix == -1 && iy == -1)
            for(int j=0; j<s[i].size(); ++j)
            {
                if(s[i][j] == 'I')
                {
                    ix = i;
                    iy = j;
                }
            }
    }
    BFS(ix, iy);
    if(!answer)
    {
        cout << "TT";
        return 0;
    }
    cout << answer;
    return 0;
}