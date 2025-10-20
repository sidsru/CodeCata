#include <string>
#include <vector>
#include <stack>
using namespace std;
bool check(string s)
{
    stack<char> stack;
    for(char& a : s)
    {
        if(a == '(' || a == '{' || a == '[') stack.push(a);
        else if((a == ')' && stack.top() == '(') 
                || (a == '}' && stack.top() == '{') 
                || (a == ']' && stack.top() == '[')) 
        {
            stack.pop();
        }
        else return false;
    }
    if(stack.size() > 0) return false;
    return true;
}

int solution(string s) {
    int answer = 0;
    for(int i = 0; i < s.size(); i++)
    {
        if(check(s)) answer++;
        s += s[0];
        s.erase(s.begin());
    }
    return answer;
}