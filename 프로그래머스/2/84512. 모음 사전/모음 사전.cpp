#include <string>
#include <vector>

using namespace std;
int cnt = -1;
int answer = 0;
string target = "";
string aeoiu = "AEIOU";
void dfs(string s)
{
    ++cnt;
    if(s == target)
    {
        answer = cnt;
        return;
    }
    if(s.size() >= 5)
        return;
    for(int i=0; i<5; ++i)
        dfs(s + aeoiu[i]);
}
int solution(string word) {
    target = word;
    dfs("");
    return answer;
}