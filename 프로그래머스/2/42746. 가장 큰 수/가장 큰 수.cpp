#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp (string a, string b)
{
    return a + b > b + a;
}
string solution(vector<int> numbers) {
    string answer = "";
    vector<string> s;
    for(int num : numbers)
        s.push_back(to_string(num));
    
    sort(s.begin(), s.end(), comp);
    if(s[0] == "0") return answer = "0";
    for(int i = 0; i<numbers.size(); i++)
    {
        answer += s[i];
    }
    return answer;
}