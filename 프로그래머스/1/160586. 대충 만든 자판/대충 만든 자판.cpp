#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    map<char, int> flag;
    for(auto& a : keymap) // keymap을 순회
    {
        for(int i=0; i<a.size(); i++) // 문자열 중 문자를 순회 
        {
            if(flag.find(a[i]) == flag.end()) // 만약 멥에 있는 문자가 아니라면 
            {
                flag.insert(pair<char, int>(a[i], i+1)); // 해당 문자를 추가
            }
            else
            {
                if(flag[a[i]]>i+1) // 이미 등록이 되어있다면 
                {
                    flag[a[i]] = i+1; //더 작은 값으로 치환시켜줌
                }
            }
        }
    }
    int count;
    
    for(auto& a : targets)
    {
        count = 0;
        for(int i=0; i<a.size(); i++)
        {
            if(flag.find(a[i]) == flag.end())
            {
                count = -1;
                break;
            }
            auto temp = a[i];
            count += flag[temp];
        }
        answer.push_back(count);
    }
    return answer;
}