#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool comp(const vector<int>& a, const vector<int>& b)
{
    if (a[0] == b[0])
    {
        return a[1] < b[1];
    }
    return a[0] < b[0];
}
int solution(vector<vector<int>> targets) {
    int answer = 0;
    sort(targets.begin(), targets.end(), comp);
    int end = 0;
    for (vector<int> a : targets)
    {
        int start = a[0];
        if (start >= end)
        {
            ++answer;
            end = a[1];
        }

        else if (a[1] < end)
        {
            end = a[1];
        }
    }
    return answer;
}