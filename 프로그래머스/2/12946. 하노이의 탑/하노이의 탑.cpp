#include <string>
#include <vector>
#include <stack>

using namespace std;

void hanoi(const int n, const int from, const int temp, const int to,vector<vector<int>>& answer)
{
    if(n == 1)
    {
        answer.push_back({from, to});
        return;
    }
    hanoi(n-1, from, to, temp, answer);
    
    answer.push_back({from, to});
    
    hanoi(n-1, temp, from, to, answer);
    return;
}
vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    hanoi(n, 1, 2, 3, answer);
    return answer;
}