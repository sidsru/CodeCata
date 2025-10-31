#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int, int>> proses;
    priority_queue<int> pq;
    for(int i=0; i<priorities.size(); i++)
    {
        proses.push({i, priorities[i]});
        pq.push(priorities[i]);
    }
    int count = 1;
    while(1)
    {
        pair<int, int> temp = proses.front();
        proses.pop();
        
        if(temp.second != pq.top())
        {
            proses.push(temp);
        }
        else
        {
            if(temp.first == location)
            {
                answer = count;
                break;
            }
            else
            {
                pq.pop();
                count++;
            }
        }
        
    }
    return answer;
}