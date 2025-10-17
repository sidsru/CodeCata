#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;
typedef pair<int, int> ii;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    map<int, int> map;
    for(int& tanger : tangerine)
    {
        ++map[tanger];
    }
    vector<ii> v(map.begin(), map.end());
    sort(v.begin(), v.end(), [](ii a, ii b)
         {
             return a.second > b.second;
         });
    int temp = 0;
    for(ii it : v)
    {
        if(temp >= k) break;
        else
        {
            temp += it.second;
            ++answer;
        }
    }
    
    return answer;
}