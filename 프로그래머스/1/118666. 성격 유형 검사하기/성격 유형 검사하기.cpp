#include <string>
#include <vector>
#include <map>
using namespace std;
map<char, int> mbti{
    {'R', 0},{'T', 0},
    {'C', 0},{'F', 0},
    {'J', 0},{'M', 0},
    {'A', 0},{'N', 0},
};
string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    int i = 0;
    
    for(auto& a : survey)
    {
        if ( choices[i] == 7 ) mbti[a[1]] += 3;
        else if ( choices[i] == 6 ) mbti[a[1]] += 2;
        else if ( choices[i] == 5 ) mbti[a[1]] += 1;
        else if ( choices[i] == 3 ) mbti[a[0]] += 1;
        else if ( choices[i] == 2 ) mbti[a[0]] += 2;
        else if ( choices[i] == 1 ) mbti[a[0]] += 3;
        ++i;
    }
    mbti['R'] >= mbti['T'] ? answer += 'R' : answer += 'T';
    mbti['C'] >= mbti['F'] ? answer += 'C' : answer += 'F';
    mbti['J'] >= mbti['M'] ? answer += 'J' : answer += 'M';
    mbti['A'] >= mbti['N'] ? answer += 'A' : answer += 'N';
    return answer;
}