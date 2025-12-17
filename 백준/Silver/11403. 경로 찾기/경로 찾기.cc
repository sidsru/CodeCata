#include <stdio.h>
#include <vector>
#include <cstring>
using namespace std;
vector<int> v[101];
bool visit[101];
void DFS(int index)
{
    for(int i=0; i<v[index].size(); ++i)
    {
        if(!visit[v[index][i]])
        {
            visit[v[index][i]] = true;
            DFS(v[index][i]);
        }
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; ++i)
        for(int j=0; j<n; ++j)
        {
            int temp;
            scanf("%d", &temp);
            if(temp)
                v[i].push_back(j);
        }
    for(int i=0;i<n; ++i)
    {
        memset(visit,false,sizeof(visit));
        DFS(i);
        for(int j=0; j<n; ++j)
        {
            if(visit[j])
                printf("1 ");
            else
                printf("0 ");
        }
        printf("\n");
    }
    
}