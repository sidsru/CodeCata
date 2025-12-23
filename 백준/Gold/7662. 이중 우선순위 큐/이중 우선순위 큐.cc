#include <stdio.h>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
class dq
{
private:
    priority_queue<int, vector<int>, greater<int>> minq;
    priority_queue<int, vector<int>, less<int>> maxq;
    map<int, int> cnt;
public:
    void insert(const int n)
    {
        minq.push(n);
        maxq.push(n);
        ++cnt[n];
    }
    void deletemax()
    {
        if(!maxq.empty())
        {
            --cnt[maxq.top()];
            maxq.pop();
        }
    }
    void deletemin()
    {
        if(!minq.empty())
        {
            --cnt[minq.top()];
            minq.pop();
        }
    }
    void clearq()
    {
        while(!minq.empty() && cnt[minq.top()] == 0)
        {
            minq.pop();
        }    
        while(!maxq.empty() && cnt[maxq.top()] == 0)
        {
            maxq.pop();
        }
    }
    void printq()
    {
        if(minq.empty() || maxq.empty())
        {
            printf("EMPTY\n");
        }
        else
        {
            printf("%d %d\n",maxq.top() ,minq.top());
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