#include <string>
#include <vector>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    int temp[1000000];
    int i = 0;
    // 1, 2, 3, 1 순서대로 배열이 나열되어있다면 asnwer를 하나 올려주고 배열을 제거
    // 위 과정을 더 이상 진행할수 없을 때 까지 반복한다
    for(int& a : ingredient)
    {
        temp[i] = a;
        if(i >= 3)
            if(temp[i] == 1 && temp[i-1] == 3 && temp[i-2] == 2 && temp[i-3] == 1)
            {
                ++answer;
                i -= 4;
            }
        ++i;
    }
    
    return answer;
}