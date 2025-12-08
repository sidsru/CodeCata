#include <iostream>
using namespace std;
int xmove[4] = {0, 0, 1, -1};
int ymove[4] = {1, -1, 0, 0};
bool vis[601][601] = {false, };
string s[601];
int answer = 0, n ,m;

void DFS(const int x, const int y)
{
    vis[x][y] = true;
    if(s[x][y] =='P')
        ++answer;
    for(int i=0; i<4; i++)
    {
        int xx = x + xmove[i];
        int yy = y + ymove[i];
        if(xx >= n || yy >= m || xx < 0 || yy < 0)
            continue;
        if(vis[xx][yy] || s[xx][yy] == 'X')
            continue;
        DFS(xx, yy);
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
    DFS(ix, iy);
    if(!answer)
    {
        cout << "TT";
        return 0;
    }
    cout << answer;
    return 0;
}