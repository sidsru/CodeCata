#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = true;
    int sum = 0;
    int temp = x;
    //자리수를 분할하여 sum변수에 분할한 수의 합을 구할 것
    while(x>0)
    {
        sum += x%10;
        x= x/10;
    }
    //나누어 떨어지는지 확인후(x%sum == 0) if문으로 구분해서 return값을 구분해줄것
    if(temp%sum == 0)  return answer;
    else return false;
}