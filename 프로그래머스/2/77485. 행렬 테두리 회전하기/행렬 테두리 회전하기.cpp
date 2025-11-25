#include <string>
#include <vector>

using namespace std;
int map[100][100];
int min(int a, int b) {return a < b ? a : b;}

int Turn (int x, int y, int xx, int yy)
{
    int temp = map[x][y];
    int Min = temp;
    for(int i=x; i < xx; i++)
    {
        Min = min(Min, map[i][y]);
        map[i][y] = map[i+1][y];
    }
    for(int i = y; i <yy; i++)
    {
        Min = min(Min, map[xx][i]);
        map[xx][i] = map[xx][i+1];
    }
    for(int i = xx; i > x; i--)
    {
        Min = min(Min, map[i][yy]);
        map[i][yy] = map[i-1][yy];
    }
    for(int i = yy; i > y; i--)
    {
        Min = min(Min, map[x][i]);
        map[x][i] = map[x][i-1];
    }
    map[x][y+1] = temp;
    return Min;
}
vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    int count = 1;
    for(int i=0; i<rows;i++)
        for(int j=0; j<columns; j++)
        {
            map[i][j] = count++;
        }
    
    for(int t=0; t<queries.size(); t++)
    {
        int x = queries[t][0]; x--;
        int y = queries[t][1]; y--;
        int xx = queries[t][2]; xx--;
        int yy = queries[t][3]; yy--;
        
        answer.push_back(Turn(x, y, xx, yy));
    }
    return answer;
}