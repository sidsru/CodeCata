#include <string>
#include <vector>

using namespace std;
int gcd(int a, int b)
{
    if(a == 0) return b;
    return gcd(b%a, a);
}
int lcm(int a, int b)
{
    return(a*b) / gcd(a, b);
}
int solution(int n) {
    int answer = lcm(6, n) / 6;
    //6과 n의 최소 공배수를 구하고 출력하는 문제
    return answer;
}