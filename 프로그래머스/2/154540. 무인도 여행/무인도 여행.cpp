#include <string>
#include <vector>
#include <cctype>
#include <algorithm>

using namespace std;
int arr[101][101];
int xpos[4] = { 0, 0, 1, -1};
int ypos[4] = { 1, -1, 0, 0};
int temp = 0, sizen = 0, sizem = 0;
void DFS(int x, int y)
{
    temp += arr[x][y];
    arr[x][y] = 0;
    for(int i=0; i<4; i++)
    {
        int xx = x + xpos[i];
        int yy = y + ypos[i];
        if(xx<0 || yy<0 || xx>=sizen || yy >= sizem)
            continue;
        if(arr[xx][yy])
            DFS(xx, yy);
    }
}
vector<int> solution(vector<string> maps) {
    vector<int> answer;
    sizen = maps.size();
    sizem = maps[0].size();
    for(int i = 0; i<maps.size(); i++)
        for(int j=0; j<maps[i].size(); j++)
            if(isdigit(maps[i][j]))
                arr[i][j] = maps[i][j] - '0';
    
    for(int i = 0; i<maps.size(); i++)
        for(int j=0; j<maps[i].size(); j++)
        {
            if(arr[i][j])
                DFS(i, j);
            if(temp != 0)
                answer.push_back(temp);
            temp = 0;
        }
    
    sort(answer.begin(), answer.end());
    
    if(!answer.size())
        answer.push_back(-1);
    return answer;
}