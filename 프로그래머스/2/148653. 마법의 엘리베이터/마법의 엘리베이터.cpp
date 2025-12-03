#include <string>
#include <vector>

using namespace std;

int solution(int storey) {
    int answer = 0;
    while(storey)
    {
        int n = storey % 10;
        storey /= 10;
        if(n < 5)
        {
            answer += n;
            
        }
        else if(5 < n)
        {
            answer += 10 - n;
            ++storey;
        }
        else
        {
            int temp = storey % 10;
            if(temp >= 5)
                ++storey;
            answer += n;
        }
    }
    return answer;
}