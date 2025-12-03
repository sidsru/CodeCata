#include<stdio.h>
#include<vector>
#include <queue>
using namespace std;
vector<int> v[1001];
bool bis[1001] = {false, };
int answer = 0;

void BFS(int n)
{
    queue<int> q;
    q.push(n);
    while(!q.empty())
    {
        int temp = q.front();
        q.pop();
        for(int i=0; i<v[temp].size(); ++i)
        {
            if(!bis[v[temp][i]])
            {
                bis[v[temp][i]] = true;
                q.push(v[temp][i]);
            }
        }
    }
    ++answer;
    return;
}
int main()
{
    int N, M;
    scanf("%d %d", &N, &M);
    for(int i=0; i<M; ++i)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for(int i=1; i<=N; ++i)
    {
        if(!bis[i])
            BFS(i);
    }
    printf("%d", answer);
    return 0;
}