#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    long sumq1 = 0, sumq2 = 0;
    queue<int> q1, q2;
    
    for(int i=0; i<queue1.size(); i++)
    {
        q1.push(queue1[i]);
        q2.push(queue2[i]);
        
        sumq1 += queue1[i];
        sumq2 += queue2[i];
    }
    long long sum = sumq1 + sumq2;
    if(sum % 2 == 1)
        return -1;
    
    while(!q1.empty() || !q2.empty())
    {
        if (sumq1 == sumq2)
            return answer;
        
        if(answer > queue1.size() * 2 + 1)
            break;
        
        if(sumq1 > sumq2)
        {
            q2.push(q1.front());
            sumq1 -= q1.front();
            sumq2 += q1.front();
            q1.pop();
        }
        else if(sumq1 < sumq2)
        {
            q1.push(q2.front());
            sumq2 -= q2.front();
            sumq1 += q2.front();
            q2.pop();
        }
        answer++;
    }
    return -1;
}