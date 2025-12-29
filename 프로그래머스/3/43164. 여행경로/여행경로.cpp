#include <string>
#include <vector>
#include <algorithm>
using namespace std;
    
bool bVisited[10001] = {false, };
vector<string> ans;
void DFS(vector<string>& v, const vector<vector<string>>& tickets)
{
    if(v.size() == tickets.size() + 1)
    {
        ans = v;
    }
    for(int i=0; i<tickets.size(); ++i)
    {
        if(!ans.empty())
        {
            return;
        }
        if(v.back() != tickets[i][0])
        {
            continue;
        }
        if(bVisited[i])
        {
            continue;
        }
        v.push_back(tickets[i][1]);
        bVisited[i] = true;
        DFS(v, tickets);
        v.pop_back();
        bVisited[i] = false;
    }
    return;
}
vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    sort(tickets.begin(), tickets.end());
    answer.push_back("ICN");
    
    DFS(answer, tickets);
    return ans;
}