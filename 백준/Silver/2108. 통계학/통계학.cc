#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;

bool comp(const pair<int,int>& a, const pair<int,int>& b)
{
    if (a.second == b.second) return a.first < b.first;
    return a.second > b.second;
}
int main ()
{
    int n, sum=0;
    vector<int> v;
    map<int, int> m;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        int a;
        cin >> a;
        sum += a;
        v.push_back(a);
        ++m[a];
    }
    sort(v.begin(), v.end());
    
    vector<pair<int, int>> v2(m.begin(), m.end());
    sort(v2.begin(), v2.end(), comp);
    //평균
    if(round((float)sum / (float)n) == -0)
        cout << 0 << '\n';
    else
        cout << round((float)sum / (float)n) << '\n';
    //중앙값
    cout << v[v.size()/2] << '\n';
    //최빈값
    if(v2[0].second != v2[1].second)
        cout << v2[0].first << '\n';
    else
        cout << v2[1].first << '\n';
    //범위
    cout << v[v.size()-1] - v[0] << '\n';
    
    return 0;
}