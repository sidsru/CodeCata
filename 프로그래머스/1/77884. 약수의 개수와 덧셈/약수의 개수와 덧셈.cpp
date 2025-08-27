#include <string>
#include <vector>

using namespace std;

int solution(int left, int right) {
    int answer = 0;
    for(int i=left; i<=right; i++)
    {
        int count = 0;
        for(int o=1; o<=i; o++)
        {
            if (i%o == 0)
            {
                ++count;
            }
        }
        if(count%2 == 0)
        {
            answer += i;
        }
        else
        {
            answer -= i;
        }
    }
    return answer;
}