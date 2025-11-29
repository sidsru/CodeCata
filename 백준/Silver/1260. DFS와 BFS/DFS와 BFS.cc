#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector <int> vec[1001];
bool DFSvisit[1001];
bool BFSvisit[1001];

void DFS(int num)
{
    DFSvisit[num] = true;
    printf("%d ", num);
    for(int i=0; i<vec[num].size(); ++i)
    {
        if(!DFSvisit[vec[num][i]])
            DFS(vec[num][i]);
    }
    return;
}

void BFS(int num)
{
    BFSvisit[num] = true;
    queue<int> q;
    q.push(num);
    while(!q.empty())
    {
        int temp = q.front();
        q.pop();
        printf("%d ", temp);
        for(int i=0; i<vec[temp].size(); ++i)
        {
            if(!BFSvisit[vec[temp][i]])
            {
                q.push(vec[temp][i]);
                BFSvisit[vec[temp][i]] = true;
            }
        }
    }
    return;
}
int main()
{
    int N, M, V;
    scanf("%d %d %d", &N, &M, &V);
    for(int i=0; i<M; ++i)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        
        vec[x].push_back(y);
        vec[y].push_back(x);
    }
    for(int i=1; i<=N; ++i)
    {
        sort(vec[i].begin(), vec[i].end());
    }
    
    DFS(V);
    printf("\n");
    BFS(V);
    
    return 0;
}