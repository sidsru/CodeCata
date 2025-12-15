#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
inline int ABS(const int& a)
{
    return a > 0 ? a : -a;
}
struct comp
{
    bool operator()(const int& a, const int& b)
    {
        if(ABS(a) == ABS(b))
            return a > b;
        return ABS(a) > ABS(b);
    }
};
int main()
{
    int n;
    scanf("%d", &n);
    priority_queue<int, vector<int>, comp> pq;
    for(int i=0; i<n; ++i)
    {
        int x;
        scanf("%d", &x);
        if(x == 0)
        {
            if(pq.empty())
                printf("0\n");
            else
            {
                printf("%d\n", pq.top());
                pq.pop();
            }
        }
        else
            pq.push(x);
    }
}