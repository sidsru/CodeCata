#include <stdio.h>
#include <vector>
using namespace std;
int n, m;
void backtracking(vector<int>& v, const int temp)
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
    for(int i=temp; i<=n; ++i)
    {
        v.push_back(i);
        backtracking(v, i);
        v.pop_back();
    }
}
int main()
{
    scanf("%d %d", &n, &m);
    vector<int> v;
    backtracking(v, 1);
}