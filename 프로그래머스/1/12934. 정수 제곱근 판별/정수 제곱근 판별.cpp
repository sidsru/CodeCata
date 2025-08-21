#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(long long n) {
    long long x= sqrt(n);
    long long answer = 0;
    if (x*x == n) answer = pow(x+1, 2);
    else  answer = -1;
    return answer;
}