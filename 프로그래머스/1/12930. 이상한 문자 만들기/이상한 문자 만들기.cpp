#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    int count = 0;
    for(int i=0; i<s.length(); i++)
    {
        if(s[i] == ' ')
        {
            count = 0;
            continue;
        }
        if(count%2 == 0)
        {
            if('a'<= s[i] && 'z'>=s[i])
            {
                s[i] -= 32;
            }
        }
        else
        {
            if('A'<= s[i] && 'Z'>= s[i])
            {
                s[i] += 32;
            }
        }
        ++count;
    }
    
    return s;
}