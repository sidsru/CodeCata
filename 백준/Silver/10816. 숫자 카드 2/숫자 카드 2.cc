// 시간제한 1초 : 간단한 시행횟수가 최악에 경우 기준 1억번 미만
// 메모리 제한 256
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main ()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);

    int n; // 최대 50만
    cin >> n;
    vector<int>v;
    for(int i=0; i<n; i++)
    {
        int a;
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    cin >> n;
    for(int i=0; i<n; i++)
    {
        int a;
        cin >> a;
        cout << upper_bound(v.begin(), v.end(), a) 
            - lower_bound(v.begin(), v.end(), a) << " ";
    }
    //cout << 1;
}