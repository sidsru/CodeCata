#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int idx;

bool comp(string a, string b)
{
    if(a[idx] < b[idx]) return true;
    else if(a[idx] == b[idx])
    {
        return a < b;
    }
    return false;
}
vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    idx = n;
    sort(strings.begin(), strings.end(), comp);
    return strings;
}