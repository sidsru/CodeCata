#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    vector<int> v;
    
    /*for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            v.push_back(max(j+1, i+1));
        }
    }*/
    for(long long i = left; i<=right; i++)
    {
        int row = i/n + 1;
        int col = i%n + 1;
        answer.push_back(max(row, col));
    }
    return answer;
}