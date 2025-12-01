#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

inline int timestr(string s)
{
    return stoi(s.substr(0, 2)) * 60 + stoi(s.substr(3, 2));
}

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    vector<pair<int, int>> v;
    for(int i=0; i<book_time.size(); ++i)
    {
        v.push_back({timestr(book_time[i][0]) , timestr(book_time[i][1]) + 10});
    }
    sort(v.begin(), v.end());
    
    priority_queue<int> pq;
    for(int i=0; i<v.size(); ++i)
    {
        if(!pq.empty() && -pq.top() <= v[i].first)
            pq.pop();
        pq.push(-v[i].second);
    }
    return pq.size();
}