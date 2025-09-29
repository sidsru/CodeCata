#include <string>
#include <vector>
#include <map>
#include <sstream>
using namespace std;

int ToDayDay(string& today)
{
    int year, month, day;
    year = stoi(today.substr(0, 4));
    month = stoi(today.substr(5, 2));
    day = stoi(today.substr(8, 2));
    return (year * 12 * 28) + ((month - 1) * 28) + day;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    map<char, int> tmap;
    vector<int> ans;
    int total = ToDayDay(today);
    
    // 약관 자르기
    for(auto& a : terms)
    {
        stringstream ss(a);
        char alpha; int month;
        ss >> alpha >> month;
        tmap[alpha] = month;
    }
    for(string& a : privacies)
    {
        int temp = ToDayDay(a);
        char A = a.back();
        temp += (tmap[A] * 28 - 1);
        
        ans.push_back(temp);
    }
    for(int i = 0; i < ans.size(); i++)
    {
        if(ans[i] < total) answer.push_back(i+1);
    }
    return answer;
}