#include <string>
#include <vector>
using namespace std;
inline int Min(const int a, const int b)
{
    return a < b ? a : b;
}
inline int Min(const int a, const int b, const int c)
{
    if(a<b)
        return a < c ? a : c;
    return b < c ? b : c;
}
int solution(string name) {
    int answer = 0;
    int mintry = 21;
    for(int i=0; i<name.size();++i)
    {
        int updown = name[i] - 'A';
        if(updown > 13)
        {
            updown = 26 - updown;
        }
        answer += updown;// 각 위치의 문자완성하는 버튼 횟수
        
        int index = i + 1;
        while(name[index] == 'A')
        {
            ++index;
        }
        int temp = Min(name.size()-1, i*2 + name.size() - index, i + (name.size() - index)*2);
        mintry = Min(mintry, temp);
    }
    answer += mintry;
    return answer;
}