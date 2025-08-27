#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    bool answer = true;
    if(s.size() != 4 && s.size() != 6)
    {
        return answer = false;
    }
    for(int i=0; i<s.length(); i++)
    {
        if(s[i]<'0'||'9'<s[i])
        {
            return answer = false;
        }
    }
    return answer;
}