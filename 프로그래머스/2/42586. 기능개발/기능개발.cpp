#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> Days;
    vector<int> v;
    int ans = 0;
    for(int i=0; i<progresses.size(); i++)
    {
        
        int temp = progresses[i];
        int j=1;
        while(1)
        {
            temp += speeds[i];
            if(temp >= 100) 
            {
                Days.push(j);
                v.push_back(j);
                //printf("%d ", Days.back());
                break;
            }
            j++;
        }
    }
    int day=1;
    while(!Days.empty())
    {
        int t=0;
        while(Days.front()<=day && !Days.empty())
        {
            Days.pop();
            t++;
        }
        if(t>0)answer.push_back(t);
        day++;
    }
    return answer;
}