#include <stdio.h>
#include <queue>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> schedule;
    for(int i=0; i<n; ++i)
    {
        int start, end;
        scanf("%d %d", &start, &end);
        schedule.push({end, start});
    }
    
    int time = schedule.top().first;
    int cnt = 1;
    schedule.pop();
    while(!schedule.empty())
    {
        if(time <= schedule.top().second)
        {
            ++cnt;
            time = schedule.top().first;
        }
        schedule.pop();
    }
    printf("%d", cnt);
    return 0;
}