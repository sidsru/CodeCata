#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    //12345
    //21232425
    //3311224455
    //위 규칙대로 123번 사람이 문제를 찍는다
    // 이때 가장 높은 점수를 받은 사람을 리턴하고\
    // 최고점이 동일하다면 오름차순으로 정렬하여 리턴한다
    // 답지의 길이 만큼 확인하며 
    // 각 학생마다 점수를 확인할때마다 올려줌
    // 마지막의 최고점인 학생을 순차적으로 answer에 넣어줌
    int one = 0;
    int two = 0;
    int three = 0;
    int onearr[5]{1, 2, 3, 4, 5};
    int twoarr[8]{2, 1, 2, 3, 2, 4, 2, 5};
    int threearr[10]{3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    int m = 0;
    int count[3]{0};
    for(int i=0; i<answers.size(); i++)
    {
        if(answers[i] == onearr[one])
        {
            ++count[0];
        }
        if(answers[i] == twoarr[two])
        {
            ++count[1];
        }
        if(answers[i] == threearr[three])
        {
            ++count[2];
        }
        ++one;
        ++two;
        ++three;
        if(one >= 5) one = 0;
        if(two >= 8) two = 0;
        if(three >= 10) three = 0;
        
    }
    for(int j=0; j<3; j++)
    {
        m = max(m, count[j]);
    }
    for(int i = 0;i<3; i++)
    {
        if(count[i] == m) answer.push_back(i+1);
    }

    return answer;
}