#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer{0,0};
    while(s != "1")
    {
        int one = 0;
        for(char& findone : s)
        {
            if(findone == '0') ++answer[1];
            else if(findone == '1')++one;
        }
        s = "";
        while(one>0)
        {
            s += to_string(one%2);
            one /= 2;
        }
        reverse(s.begin(), s.end());
        ++answer[0];
    }
    return answer;
}