#include <string>
#include <vector>

using namespace std;
vector<vector<int>> map;
void DFS(int x, int y, int k, vector<int>& ans)
{
    bool zero, one;
    zero = one = true;
    for(int i=x; i<x + k; i++)
    {
        for(int j = y; j<y + k; j++)
        {
            if(map[i][j] == 1) zero = false;
            if(map[i][j] == 0) one = false;
        }
        if(!one && !zero) break;
    }
    
    if(zero == true)
    {
        ans[0]++;
        return;
    }
    if(one == true)
    {
        ans[1]++;
        return;
    }
    
    DFS(x, y, k/2, ans);
    DFS(x, y+k/2, k/2, ans);
    DFS(x+k/2, y, k/2, ans);
    DFS(x+k/2, y+k/2, k/2, ans);
}
vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer(2, 0);
    map = arr;
    DFS(0, 0, arr.size(), answer);
    return answer;
}