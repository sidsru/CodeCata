#include <string>
#include <vector>
#include <queue>
using namespace std;
bool visible[101][101];
inline bool check(const int& x, const int& y, const int& n, const int& m)
{
    return (x < 0 || y < 0 || n <= x || m <= y);
}
int BFS(const int& x, const int& y,const vector<string>& board)
{
    int xmove[4] = {1, -1, 0, 0};
    int ymove[4] = {0, 0, 1, -1};
    queue<pair<pair<int, int>, int>> q;
    q.push({{x, y}, 0});
    visible[x][y] = true;
    while(!q.empty())
    {
        pair<int, int> xy = q.front().first;
        int cnt = q.front().second;
        q.pop();
        for(int i=0; i<4; ++i)
        {
            int xx = xy.first;
            int yy = xy.second;
            while(true)
            {
                xx += xmove[i];
                yy += ymove[i];
                if(check(xx, yy, board.size(), board[0].size()) || board[xx][yy] == 'D')
                    break;
            }
            xx -= xmove[i];
            yy -= ymove[i];
            if(visible[xx][yy])
                continue;
            if(board[xx][yy] == 'G')
                return cnt + 1;
            q.push({{xx, yy}, cnt+1});
            visible[xx][yy] = true;
        }
    }
    return -1;
}
int solution(vector<string> board) {
    int answer = 0;
    for(int i=0; i<board.size(); ++i)
        for(int j=0; j<board[i].size(); ++j)
            if(board[i][j] == 'R')
                answer = BFS(i, j, board);
    return answer;
}