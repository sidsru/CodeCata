#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int n;
bool visible[26][26] = {false, };
bool maps[26][26] = {false, };
vector<int> v;
int xmove[4] = {1, -1, 0, 0};
int ymove[4] = {0, 0, 1, -1};
inline bool map(int x, int y)
{
    return (x < 0 || y < 0 || n <= x || n <= y);
}
void BFS(int x, int y)
{
    if(visible[x][y] || !maps[x][y])
        return;
    queue<pair<int, int>>q;
    q.push({x, y});
    visible[x][y] = true;
    int cnt = 1;
    while(!q.empty())
    {
        int xtemp = q.front().first;
        int ytemp = q.front().second;
        q.pop();
        for(int i=0; i<4; ++i)
        {
            int xx = xtemp + xmove[i];
            int yy = ytemp + ymove[i];
            if(map(xx, yy) || visible[xx][yy]  || !maps[xx][yy])
                continue;
            ++cnt;
            visible[xx][yy] = true;
            q.push({xx, yy});
        }
    }
    v.push_back(cnt);
    return;
}
int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    //cout.tie(NULL);
    string s;
    cin >> n;
    for(int i=0; i<n; ++i)
    {
        cin >> s;
        for(int j=0; j<n; ++j)
        {
            if(s[j] == '1')
            {
                maps[i][j] = true;
            }
        }
    }
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<n; ++j)
        {
            if(maps[i][j])
            {
                BFS(i, j);
            }
        }
    }
    sort(v.begin(), v.end());
    cout << v.size() << '\n';
    for(int a : v)
        cout << a << '\n';
}