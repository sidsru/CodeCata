#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    //n이하의 짝수를 찾고 오름차순으로 정렬해서 반환
    for(int i=1; i<=n; i++)
    {
        if(i%2 != 0)
        {
            answer.push_back(i);
        }
    }
    return answer;
}