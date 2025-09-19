#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    // 문자열 분해 해야함 
    // 첫글자는 x
    // x가 아닌 글자들이 나온 횟수를 카운트 ,x가 나온 횟수를 카운트
    // x와 !=x 의 글자가 같은 횟수라면 분리후 종료
    // 분리 이후 이과정을 문자열이 끝날때까지 반복
    int xcount = 0;
    int ncount = 0;
    char temp = ' ';
    for(char& a : s)
    {
        if (temp == ' ')
        {
            temp = a;
            ++xcount;
        }
        else if (temp == a)
        {
            ++xcount;
        }
        else
        {
            ++ncount;
        }
        if (xcount == ncount)
        {
            temp = ' ';
            xcount = 0;
            ncount = 0;
            ++answer;
        }
    }
    if (temp != ' ')
    {
        ++answer;
    }
    return answer;
}