#include <string>
#include <vector>
#include <map>
using namespace std;

int fetigue[3][3] = {{1,1,1}, {5,1,1}, {25, 5, 1}};
map<string, int> m;
void DFS(vector<int>& picks, const vector<string>& minerals,int index,int& answer, int sum)
{
    if(index >=minerals.size() ||(picks[0] == 0 && picks[1] == 0 && picks[2] == 0))
    {
        answer = min(answer,sum);
        return;
    }
    for(int i=0; i<3; ++i)
    {
        if(picks[i] > 0)
        {
            --picks[i];
            int tempidx = index;
            int tempsum = sum;
            for(; tempidx<minerals.size() && tempidx<index+5; ++tempidx)
                tempsum += fetigue[i][m[minerals[tempidx]]];
            
            DFS(picks,minerals,tempidx,answer,tempsum);
            ++picks[i];
        }
    }
}
int solution(vector<int> picks, vector<string> minerals) {
    int answer = 25 * 50;
    m["diamond"] = 0;
    m["iron"] = 1;
    m["stone"] = 2;
    DFS(picks, minerals,0,answer,0);
    return answer;
}