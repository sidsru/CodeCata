#include <string>
#include <vector>
#include <map>
#include <set>
#include <sstream>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(), 0);
    
    map<string, int> index;
    for(auto i = 0; i < id_list.size(); i++)
    {
        index[id_list[i]] = i;
    }
    
    // 신고한 사람, 신고당한 사람
    map<string, set<string>> list;
    for(auto it : report)
    {
        stringstream ss(it);
        string from, to;
        ss >> from >> to;
        
        list[to].insert(from);
    }
    for(auto it : list)
    {
        if(it.second.size() >= k)
        {
            for(auto iter : it.second)
            {
                answer[index[iter]]++;
            }
        }
    }
    return answer;
}
// 유저당 여러번 신고를 할수 있음
// 다만 동일 유저가 다른 동일 유저를 중복에서 신고하는 경우 최초를 제외하고 무시
// 결과로 각 유저가 신고 결과 메일을 받은횟수를 반환