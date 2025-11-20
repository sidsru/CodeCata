#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<vector<int>> map(n+1, vector<int>(n+1));
    vector<int> answer;
    int top = 1, bottom = n, left = 1, right = 0;
    int state = 0, num = 1, maxnum = (n *(n+1)) / 2;
    while(num <= maxnum)
    {
        switch(state)
        {
            case 0:
                for(int i=top; i<=bottom;i++)
                    map[i][left] = num++;
                top++;
                left++;
                state = 1;
                break;
                
            case 1:
                for(int i=left;i<= bottom-right;i++)
                    map[bottom][i] = num++;
                bottom--;
                state = 2;
                break;
                
            case 2:
                for(int i=bottom;i>=top;i--)
                    map[i][i-right] = num++;
                right++;
                top++;
                state = 0;
                break;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1; j<=i; j++)
        {
            answer.push_back(map[i][j]);
        }
    }
    return answer;
}