#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    multiset<string> com(completion.begin(), completion.end());
    multiset<string> par(participant.begin(), participant.end());
    for(auto& it : par)
    {
        if (com.find(it) == com.end())
        {
            answer = it;
        }
        else
        {
            com.erase(com.find(it));
        }
    }
    return answer;
}