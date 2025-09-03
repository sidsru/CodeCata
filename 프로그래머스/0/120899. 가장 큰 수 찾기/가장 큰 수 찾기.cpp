#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array) {
    vector<int> answer;
    int m = 0;
    for(auto a : array)
    {
        m = max(m, a);
        
    }
    answer.push_back(m);
    auto it = find(array.begin(), array.end(), m)- array.begin();
    
    answer.push_back(it);
    return answer;
}