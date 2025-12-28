#include <stdio.h>
#include <vector>
using namespace std;
int n,m;
void backtracking(const int num, vector<int>& v , bool* visited)
{
    if(v.size() == m)
    {
        for(int a : v)
        {
            printf("%d ", a);
        }
        printf("\n");
        return;
    }
    
    for(int i=num; i<=n; ++i)
    {
        if(visited[i])
        {
            continue;
        }
        visited[i] = true;
        v.push_back(i);
        backtracking(i, v, visited);
        v.pop_back();
        visited[i] = false;
    }
}

int main ()
{
    scanf("%d %d", &n, &m);
    vector<int> v;
    for(int i=1; i<=n; ++i)
    {

        bool visited[9] = {false, };
        v.push_back(i);
        visited[i] = true;
        backtracking(i, v, visited);
        v.pop_back();
        visited[i] = false;
    }
    
}