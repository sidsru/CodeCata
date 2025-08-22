#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    long long n = num;
    int answer = 0;
    while(n != 1)
    {
        if(n%2 == 0)
        {
            n /= 2;
        }
        else
        {
            n *= 3;
            ++n;
        }
        if(answer >= 500)
        {
            return -1;
        }
        ++answer;
    }
    
    return answer;
}