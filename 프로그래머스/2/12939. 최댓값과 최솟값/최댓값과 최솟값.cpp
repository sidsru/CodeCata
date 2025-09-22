#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string s) {
    string answer = "";
    vector<int> vec;
    string temp = "";
    for(auto& a : s)
    {
        if(a == ' ')
        {
            vec.push_back(stoi(temp));
            temp = "";
        }
        else temp += a;
    }
    vec.push_back(stoi(temp));
    sort(vec.begin(), vec.end());
    
    answer += to_string(vec[0]) + " " + to_string(vec[vec.size()-1]);
    return answer;
}