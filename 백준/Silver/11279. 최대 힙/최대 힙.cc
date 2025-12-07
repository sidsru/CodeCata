#include <stdio.h>
#include <queue>
using namespace std;

int main()
{
    int n;
    priority_queue<int> pq;
    scanf("%d", &n);
    for(int i=0; i<n; ++i)
    {
        int m;
        scanf("%d", &m);
        if(m == 0)
        {
            if(!pq.empty())
            {
                printf("%d\n", pq.top());
                pq.pop();
            }
            else
                printf("0\n");
        }
        else
            pq.push(m);
    }
}