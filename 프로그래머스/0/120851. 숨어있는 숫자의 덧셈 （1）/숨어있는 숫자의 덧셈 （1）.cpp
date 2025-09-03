#include <string>
#include <vector>

using namespace std;

int solution(string my) {
    int answer = 0;
    for(int i=0; i<my.length(); i++)
    {
        if(my[i]>='0' && my[i]<='9')
        {
            answer += my[i]-'0';
        }
    }
    return answer;
}