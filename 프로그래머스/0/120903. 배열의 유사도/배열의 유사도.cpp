#include <string>
#include <vector>

using namespace std;

int solution(vector<string> s1, vector<string> s2) {
    int answer = 0;
    for(auto a : s1)
    {
        for(auto b : s2)
        {
            if(a == b)
            {
                ++answer;
                break;
            }
        }
    }
    return answer;
}