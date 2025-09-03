#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string s) {
    string answer = "";
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]>='A' && s[i] <= 'Z')
        {
            s[i] -= 'A';
            s[i] += 'a';
        }
    }
    sort(s.begin(), s.end());
    return answer = s;
}