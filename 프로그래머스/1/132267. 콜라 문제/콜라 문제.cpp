#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;
    while(n>=a)
    {
        // n/a 번 만 큼 b개의 콜라를 줄것이며
        answer += n / a * b;
        //현재 갯수에 받은 콜라와 남는 콜라의 나머지를 반영 해줌
        n = (n / a * b) + (n % a);
    }
    return answer;
}