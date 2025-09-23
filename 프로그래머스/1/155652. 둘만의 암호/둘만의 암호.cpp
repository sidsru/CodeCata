#include <string>
#include <vector>
#include <set>
using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    // s에 있는 알파벳을 전부 index만큼 뒤에 있는 알파벳으로 치환
    // 치환 과정에서 스킵에 있는 알파벳이라면 스킵한다
    
    //암호로 바꿀 문자열을 순회
    for(char& a : s)
    {
        // n번째 알파벳
        int c = a - 'a';
        int i = 0;
        //변경되는 문자열의 범위중 스킵할 문자가 포함되어있다면 저장
        while(i < index)
        {
            ++c;
            a = (c % 26) + 'a';
            if(skip.find(a) == string::npos) ++i;
        }
        answer += a;
    }
    return answer;
}