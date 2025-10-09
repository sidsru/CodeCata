#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int temp = n;
    while(temp)
    {
        int t = 0;
        for(int i=temp; i > 0; i++)
        {
            t += i;
            if(t == n)
            {
                ++answer;
                break;
            }
            else if(t > n) break;
        }
        --temp;
    }
    return answer;
}