#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
vector<string> swaps(vector<string> v, string a)
{
    auto it = find(v.begin(), v.end(), a);
    
    string temp = v[it - v.begin()];
    v[it - v.begin()] = v[it - v.begin() - 1];
    v[it - v.begin() - 1] = temp;
    return v;
}
vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    // 경주의 최종 1등을 반환
    // 1번째: 시간초과
    // 
    map<int, string> a;
    map<string, int> b;
    for(int i=0; i<players.size(); i++)
    {
        a[i] = players[i];
        b[players[i]] = i;
    }
    for(int i=0; i<callings.size(); i++)
    {
        int idx = b[callings[i]];
        string change = a[idx - 1];
        a[idx - 1] = callings[i];
        a[idx] = change;
        b[callings[i]] = idx - 1;
        b[change] = idx;
    }
    for(auto c : a) answer.push_back(c.second);
    return answer;
}