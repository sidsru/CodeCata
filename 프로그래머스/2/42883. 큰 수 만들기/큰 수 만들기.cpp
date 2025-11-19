#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int size = number.size();
    for(int i=0; i<size; i++)
    {
        if(answer.size() >= size-k)
            break;
        int cursor = 0;
        char temp = number[cursor];
        for(int j=0; j<=k; j++)
        {

            if(temp<number[j])
            {
                temp = number[j];
                cursor = j;
            }
        }
        answer += number[cursor];
        number.erase(0, cursor+1);
        k -= cursor;
        if(k <= 0)
        {
            answer += number;
            break;
        }
    }
    return answer;
}