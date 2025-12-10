#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

vector<int> v[101];
int n, m;
int BFS(const int& s)
{
    bool visible[101] = {false, };
    int sum = 0;
    visible[s] = true;
    queue<pair<int,int>> q;
    q.push({s, 0});
    while(!q.empty())
    {
        int temp = q.front().first;
        int cnt = q.front().second + 1;
        q.pop();
        for(int i=0; i<v[temp].size(); ++i)
        {
            if(visible[v[temp][i]])
                continue;
            q.push({v[temp][i], cnt});
            visible[v[temp][i]] = true;
            sum += cnt;
        }
    }
    return sum;
}
int main()
{
    scanf("%d %d", &n, &m);
    for(int i=0; i<m; ++i)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int temp = 123456789, answer = 0;
    for(int i=1; i<=n; ++i)
    {
        int bfs = BFS(i);
        
        if(bfs < temp)
        {
            temp = bfs;
            answer = i;
        }
    }
    printf("%d", answer);
}