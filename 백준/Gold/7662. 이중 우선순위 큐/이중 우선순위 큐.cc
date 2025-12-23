#include <queue>
#include <iostream>
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
            clearq();
        }
    }
    void deletemin()
    {
        if(!minq.empty())
        {
            bIsAlive[minq.top().second] = false;
            minq.pop();
            clearq();
        }
    }
    inline void clearq()
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
    inline string printq() const
    {
        if(minq.empty() && maxq.empty())
        {
            return "EMPTY\n";
        }
        else
        {
            return to_string(maxq.top().first) + " " +to_string(minq.top().first) +"\n";
        }
    }
};

int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int t;
    cin >> t;
    for(int i=0; i<t; ++i)
    {
        dq q;
        int k;
        cin >> k;
        for(int j=0; j<k; ++j)
        {
            char c;
            cin >> c;
            int n;
            cin >> n;
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
            }
        }
        q.clearq();
        cout << q.printq();
    }
}