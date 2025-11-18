#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    stack<int> box;
    queue<int> container;
    for(int i=1; i<=order.size(); i++)
    {
        container.push(i);
    }
    int i=0;
    while(1)
    {
        if(!container.empty() && container.front() == order[i])
        {
            answer++;
            i++;
            container.pop();
        }
        else if( !box.empty() && order[i] == box.top())
        {
            answer++;
            i++;
            box.pop();
        }
        else if(!container.empty())
        {
            box.push(container.front());
            container.pop();
        }
        else
        {
            break;
        }
    }
    return answer;
}