// 프로그레머스
#include <string>
#include <vector>
#include <cmath>

using namespace std;
//                 제곱   ,          왼쪽 윈도우,          오른쪽 윈도우
int div(const long long n,const long long l,const long long r)
{
    if (r < l)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }
    int sum = 0;
    long long s = n / 5;
    for (long long i = 0; i < 5; ++i)
    {
        if (i == 2)
        {
            continue; 
        }
        sum += div(s, max(s * i, l) - (s * i), min(s * (i + 1) - 1, r) - (s * i));
    }
    return sum;
}
int solution(int n, long long l, long long r) 
{
    return div(pow(5, n), l-1, r-1);
}
