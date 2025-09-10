#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<string> babbling) 
{
    int answer = 0;
    // 단어 4개만 말할수 있으며 다른 단어의 조합으로 옹알이를 함
    // 같은 단어를 연속해서 말할 수 없다
    // 입력이 들어오는 문자열중 말할수 있는 단어는 몇개인지 리턴
    vector<string> arr {"aya", "ye", "woo", "ma"};
    int flag = -1;
    // 문자열을 순회
    for ( int i = 0; i < babbling.size(); i++)
    {
        for ( int j = 0; j < babbling[i].size(); j++ )
        {
            if (babbling[i].substr(j, arr[0].size()) == arr[0] && flag != 0)
            {
                j += 2;
                flag = 0;
            }
            else if (babbling[i].substr(j, arr[1].size()) == arr[1] && flag != 1)
            {
                j += 1;
                flag = 1;
            }
            else if (babbling[i].substr(j, arr[2].size()) == arr[2] && flag != 2)
            {
                j += 2;
                flag = 2;
            }
            else if (babbling[i].substr(j, arr[3].size()) == arr[3] && flag != 3)
            {
                j += 1;
                flag = 3;
            }
            else
            {
                flag = -1;
                break;
            }
        }
        if ( flag != -1)
        {
            ++answer;
            flag = -1;
        }
    }
    return answer;
}