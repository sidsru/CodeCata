#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(vector<int> food) {
    string answer = "";
    
    //food[i]는 음식의 갯수가 들어가있음
    //음식의 갯수는 2명 모두 같은 수 만큼 먹어야함
    //음식나열이 끝나면 물을 배치 후 반전 시켜서 한번더 배치
    for(int i=1; i<food.size(); i++)
    {
        while(food[i]>=2)
        {
            food[i] -= 2;
            answer += to_string(i);
        }
    }
    string s = answer;
    reverse(s.begin(), s.end());
    answer += "0" + s;
    return answer;
}