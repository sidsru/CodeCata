#include <stdio.h>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
class dq
{
private:
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minq;
    priority_queue<pair<int, int>> maxq;
    bool bIsAlive[1000000] = {false, };
    int cnt = 0;
public:
    void insert(const int n)
    {
        minq.push({n, cnt});
        maxq.push({n, cnt});
        bIsAlive[cnt] = true;
        ++cnt;
    }
    void deletemax()
    {
        if(!maxq.empty())
        {
            bIsAlive[maxq.top().second] = false;
            maxq.pop();
        }
    }
    void deletemin()
    {
        if(!minq.empty())
        {
            bIsAlive[minq.top().second] = false;
            minq.pop();
        }
    }
    void clearq()
    {
        while(!minq.empty() && !bIsAlive[minq.top().second])
        {
            minq.pop();
        }    
        while(!maxq.empty() && !bIsAlive[maxq.top().second])
        {
            maxq.pop();
        }
    }
    void printq()
    {
        if(minq.empty())
        {
            printf("EMPTY\n");
        }
        else
        {
            printf("%d %d\n",maxq.top().first ,minq.top().first);
        }
    }
};

int main ()
{
    int t;
    scanf("%d", &t);
    for(int i=0; i<t; ++i)
    {
        dq q;
        int k;
        scanf("%d", &k);
        for(int j=0; j<k; ++j)
        {
            char c;
            int n;
            scanf(" %c %d", &c, &n);
            if(c == 'I')
            {
                q.insert(n);
            }
            else if(c == 'D')
            {
                if(n == -1)
                {
                    q.deletemin();
                }
                else if(n == 1)
                {
                    q.deletemax();
                }
                q.clearq();
            }
        }
        q.clearq();
        q.printq();
    }
}