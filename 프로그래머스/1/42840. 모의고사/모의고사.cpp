#include <string>
#include <vector>

using namespace std;
inline int Max(const int& a, const int& b) {return a > b ? a : b; }
vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> one{1, 2, 3, 4, 5};
    vector<int> two{2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> three{3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    int m = 0;
    int count[3]{0,};
    for(int i=0; i<answers.size(); ++i)
    {
        if(answers[i] == one[i%one.size()])
            ++count[0];        
        if(answers[i] == two[i%two.size()])
            ++count[1];
        if(answers[i] == three[i%three.size()])
            ++count[2];
    }
    m = Max(Max(count[0],count[1]),count[2]);

    for(int i=0; i<3; ++i)
        if(m == count[i])
            answer.push_back(i+1);
    return answer;
}