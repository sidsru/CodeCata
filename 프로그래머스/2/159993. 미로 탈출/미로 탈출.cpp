#include <string>
#include <vector>
#include <queue>
using namespace std;

int BFS(int x, int y, char target, vector<string>& map)
{
    bool vis[101][101] = {false, };
    int xmove[4] = {0, 0, 1 ,-1};
    int ymove[4] = {1 ,-1, 0, 0};
    vis[x][y] = true;
    queue<pair<pair<int, int>, int>> q;
    q.push({{x,y},0});
    int time = 2147000000;
    while(!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int ptime = q.front().second;
        q.pop();
        if(map[x][y] == target)
            time = min(time, ptime);
        for(int i=0; i<4; ++i)
        {
            int xx = x + xmove[i];
            int yy = y + ymove[i];
            if(map.size() <= xx || map[0].size() <= yy || yy < 0 || xx < 0)
                continue;
            if(map[xx][yy] == 'X'|| vis[xx][yy])
                continue;
            q.push({{xx, yy}, ptime+1});
            vis[xx][yy] = true;
        }
    }
    return time == 2147000000 ? -1 : time;
}


int solution(vector<string> maps) {
    int answer = 0;
    int sx, sy, lx, ly;
    for(int i=0; i<maps.size();++i)
        for(int j=0; j<maps[i].size();++j)
        {
            if(maps[i][j] == 'S')
            {
                sx = i; sy = j;
            }
            if(maps[i][j] == 'L')
            {
                lx = i; ly = j;
            }
        }
    int stl = BFS(sx, sy, 'L', maps);
    if(stl == -1)
        return -1;
    
    int lte = BFS(lx, ly, 'E', maps);
    if(lte == -1)
        return -1;
    return stl + lte;
}