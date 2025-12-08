#include <algorithm>
#include <vector>

using namespace std;
int colum;
bool comp(const vector<int>& a, const vector<int>& b)
{
    if(a[colum] == b[colum])
    {
        return a[0] > b[0];
    }
    return a[colum] < b[colum];
}
int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;
    colum = col-1;
    sort(data.begin(), data.end(), comp);
    int x = 0;
    for(int i=row_begin; i<=row_end;++i)
    {
        int temp = 0;
        for(int j=0; j<data[i-1].size(); ++j)
        {
            temp += data[i-1][j] % i;
        }
        x ^= temp;
    }
    return answer = x;
}