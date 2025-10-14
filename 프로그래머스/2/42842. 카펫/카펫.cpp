#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int area = brown + yellow;
    
    for(int height = 3; height <= sqrt(area); height++)
    {
        if(area % height == 0)
        {
            int width = area / height;
            
            if(((height + width) * 2 - 4) == brown)
            {
                answer.push_back(width);
                answer.push_back(height);
                break;
            }
        }
    }
    return answer;
}