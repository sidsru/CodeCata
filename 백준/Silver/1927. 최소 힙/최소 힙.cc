#include <stdio.h>
#include <queue>
using namespace std;
int main()
{
    int N;
    scanf("%d", &N);
    priority_queue<int, vector<int>, greater<int>> q;
    for(int i=0; i<N; ++i)
    {
        int M;
        scanf("%d", &M);
        switch(M)
        {
            case 0:
                if(q.empty())
                    printf("0\n");
                else
                {
                    printf("%d\n", q.top());
                    q.pop();
                }
                break;
            default:
                q.push(M);
                break;
        }
        
    }
}