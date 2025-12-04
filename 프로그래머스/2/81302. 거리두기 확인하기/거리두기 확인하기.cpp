#include <string>
#include <vector>
#include <queue>
using namespace std;

int movex[4] = { 0, 0, 1, -1 };
int movey[4] = { 1, -1, 0, 0 };

bool BFS (int x,int y, vector<string>& map)
{
    int cnt = 0;
    bool vis[5][5] = {false, };
    queue<pair<pair<int,int>,int>> q;
    q.push({{x,y},cnt});
    vis[x][y] = true;
    while(!q.empty())
    {
        int xtemp = q.front().first.first;
        int ytemp = q.front().first.second;
        int ncnt = q.front().second +1;
        q.pop();
        for(int i=0; i<4; ++i)
        {
            if(ncnt > 2)
                break;
            int nx = xtemp + movex[i];
            int ny = ytemp + movey[i];
            if(nx < 0 || ny < 0 || nx >=5 || ny >= 5)
                continue;
            if(vis[nx][ny])
                continue;
            if(map[nx][ny] == 'X')
                continue;
            if(map[nx][ny] == 'P')
                return false;
            q.push({{nx, ny}, ncnt});
            vis[nx][ny] = true;
        }
    }
    return true;
}
int findhuman(vector<string>& map)
{
    for(int i=0; i<5; ++i)
        for(int j=0; j<5; ++j)
            if(map[i][j] == 'P')
                if(!BFS(i,j, map))
                    return 0;
    return 1;
}
vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for(vector<string> place : places)
    {
        answer.push_back(findhuman(place));
    }
    return answer;
}