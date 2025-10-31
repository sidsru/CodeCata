// 시간제한 1초 : 간단한 시행횟수가 최악에 경우 기준 1억번 미만
// 메모리 제한 256
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main ()
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);

    int n, m; // 최대 50만
    cin >> n;
    map<int, int>map;
    for(int i=0; i<n; i++)
    {
        int a;
        cin >> a;
        ++map[a];
    }
    cin >> m;
    for(int i=0; i<m; i++)
    {
        int a;
        cin >> a;
        auto it = map.find(a);
        if(it != map.end()) cout << it->second << " ";
        else cout << "0" << " ";
    }
    //cout << 1;
}