#include<string>
#include <iostream>
#include <stack>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<char> stack;
    for(char& cap : s)
    {
        if(cap == '(')
        {
            stack.emplace(cap);
        }
        else
        {
            if(stack.empty()) return false;
            else stack.pop();
        }
    }
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;

    return stack.empty();
}