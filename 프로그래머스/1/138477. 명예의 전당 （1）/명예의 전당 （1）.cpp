#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool comp(int a, int b)
{
    return a > b;
}

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    vector<int>temp;
    int size = 0;
    //multiset<int, greater<int>> s;
    for(auto a : score)
    {
        
        temp.push_back(a);
        sort(temp.begin(), temp.end(), comp);
        if(temp.size()<=k)
        {
            answer.push_back(temp[size]);
            ++size;
        }
        else
        {
            answer.push_back(temp[k-1]);
        }
    }
    //k등수까지 표시 되는 명예의 전당에서 7일간 최하위 점수를 answer에 넣어줘라
    
    return answer;
}