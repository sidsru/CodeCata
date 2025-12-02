#include <string>
#include <vector>
#include <cmath>

using namespace std;
inline long long sqsqrt(long long a, long long b)
{
    return sqrt(a*a - b*b);
}
long long solution(int k, int d) {
    long long answer = 0;
    for(int i = 0; i<=d; i+=k)
    {
        int x = sqsqrt(d, i);
        answer += x/k;
        ++answer;
    }
    return answer;
}