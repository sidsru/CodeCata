#include <string>
#include <string.h>
#include <vector>

using namespace std;

int x[10];
int y[10];

int* CountNum(int arr[], string s)
{
    //배열에 s[i]의 문자가 해당하는 자리의 카운트를 올려줌
    for(int i=0; i<s.size(); i++) arr[s[i]-'0']++;
    //완성된 카운트를 반환
    return arr;
}
string solution(string X, string Y) {
    string answer = "";
    CountNum(x, X);
    CountNum(y, Y);
    //반대로 집어넣기 위해 9부터 시작 1씩 감소
    for(int i=9; i>=0; i--)
    {
        //if(x[i]==0 || y[i]==0) continue;
        //자리수의 나온 횟수중 가장 적은 쪽을 저장
        int num = min(x[i],y[i]);
        for(int j=0; j < num; j++)
        {
            answer += to_string(i);
        }
    }
    if(answer == "") return "-1";
    else if(answer[0] == '0') return "0";
    return answer;
    
}