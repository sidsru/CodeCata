#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string my) {
    string answer = "";
    for(int i=0; i<my.length(); i++)
    {
        if(my[i]!='a' && my[i]!='e'&& my[i]!='i' && my[i]!='o' && my[i]!='u')
        {
            answer += my[i];
        }
    }
    return answer;
}