// 프로그레머스
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int xmove[4] = { 0, 0, 1, -1 };
int ymove[4] = { 1, -1, 0, 0 };
bool visited[501][501][4];

int change(const int dir, const char c)
{
    if (c == 'L')
    {
        switch (dir)
        {
        case 0:
            return 3;

        case 1 :
            return 2;

        case 2 :
            return 0;

        case 3:
            return 1;
        }
    }
    switch (dir)
    {
    case 0:
        return 2;

    case 1:
        return 3;

    case 2:
        return 1;

    case 3:
        return 0;
    }
}

int simullation(const int x, const int y, const int dir, const int depth, const vector<string>& grid)
{
    if (visited[x][y][dir] == true)
    {
        return depth;
    }
    visited[x][y][dir] = true;
    int ndir = dir;
    if (grid[x][y] != 'S')
    {
        ndir = change(dir, grid[x][y]);
    }
    int nx = x + xmove[ndir], ny = y + ymove[ndir];
    if (nx < 0)
    {
        nx = grid.size() -1;
    }
    if (ny < 0)
    {
        ny = grid[0].size() - 1;
    }
    if (nx >= grid.size())
    {
        nx = 0;
    }
    if (ny >= grid[0].size())
    {
        ny = 0;
    }
    return simullation(nx, ny, ndir, depth+1, grid);
}

vector<int> solution(vector<string> grid) {
    vector<int> answer;
    for (int i = 0; i < grid.size(); ++i)
    {
        for (int j = 0; j < grid[i].size(); ++j)
        {
            for (int k = 0; k < 4; ++k)
            {
                int result = simullation(i, j, k, 0, grid);
                if (result)
                {
                    answer.push_back(result);
                }
            }
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}