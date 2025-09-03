#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> temp;
    for(auto a : commands)
    {
        for(int i=a[0]; i<=a[1]; i++)
        {
            temp.push_back(array[i-1]);
        }
        sort(temp.begin(), temp.end());
        answer.push_back(temp[a[2]-1]);
        temp.clear();
    }
    return answer;
}