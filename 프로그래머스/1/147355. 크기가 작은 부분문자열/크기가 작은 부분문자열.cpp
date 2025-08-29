#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    string s;
    for(int i=0; i<t.length()-p.size()+1; i++)
    {
        s = t.substr(i, p.size());
        if(s <= p)
        {
            ++answer;
        }
    }
    return answer;
}