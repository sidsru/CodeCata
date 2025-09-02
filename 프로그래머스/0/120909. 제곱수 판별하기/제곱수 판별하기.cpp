#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
    int answer = 2;
    //n에 루트를 씌웠을때 정수인지 확인해야함
    long long a = sqrt(n);
    if(a - sqrt(n) == 0)
    {
        answer = 1;
    }
    return answer;
}