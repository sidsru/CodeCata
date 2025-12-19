#include <string>
#include <vector>

using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;
    vector<int> temp;
    temp.push_back(k);
    while(k != 1)
    {
        if(k & 1)
        {
            k *= 3;
            ++k;
        }
        else
            k >>=1;
        temp.push_back(k);
    }
    for(int i=0; i<ranges.size(); ++i)
    {
        int start = ranges[i][0];
        int end = temp.size()-1 + ranges[i][1];
        
        double tmp = 0;
        for(int index = start; index<end; ++index)
            tmp += (double)(temp[index] + temp[index+1]) / 2;
        if(start > end)
            answer.push_back(-1.0);
        else
            answer.push_back(tmp);
    }
    return answer;
    
}