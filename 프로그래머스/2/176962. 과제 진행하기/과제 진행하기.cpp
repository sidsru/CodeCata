#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>
using namespace std;
inline int minutes(string s)
{
    return stoi(s.substr(0,2))*60 + stoi(s.substr(3,2));
}
bool compplan(vector<string> v1, vector<string> v2)
{
    return minutes(v1[1]) < minutes(v2[1]);
}
vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    stack<pair<string, int>> stacks;
    sort(plans.begin(), plans.end(), compplan);

    int time = minutes(plans[0][1]);
    for(vector<string> plan : plans)
    {
        int newtime = minutes(plan[1]);
        int t = newtime - time;
        while(!stacks.empty() && t > 0)
        {
            if(t >= stacks.top().second)
            {
                t -= stacks.top().second;
                answer.push_back(stacks.top().first);
                stacks.pop();
            }
            else
            {
                stacks.top().second -= t;
                t = 0;
            }
        }
        stacks.push({plan[0], stoi(plan[2])});
        time = newtime;
    }
    while(!stacks.empty())
    {
        answer.push_back(stacks.top().first);
        stacks.pop();
    }
    return answer;
}