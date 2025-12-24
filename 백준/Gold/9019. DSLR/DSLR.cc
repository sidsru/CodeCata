#include <iostream>
#include <queue>
#include <string>
using namespace std;
inline int D(int n)
{
    return (n*2) % 10000;
}
inline int S(int n)
{
    if(n - 1 < 0)
        return 9999;
    return n-1;
}
inline int L(int n)
{
    int ln = n / 1000;
    return ((n*10)%10000) + ln;
}
inline int R(int n)
{
    int rn = n%10;
    return (rn*1000) + (n/10);
}

string BFS(const int n, const int target)
{
    bool visited[10001] = {false, };
    queue<pair<int, string>> q;
    q.push({n, ""});
    visited[n] = true;
    while(!q.empty())
    {
        //cout << "bfs\n";
        int nums = q.front().first;
        string temp = q.front().second;
        q.pop();
        if(nums == target)
        {
            return temp;
        }
        if(!visited[D(nums)])
        {
            visited[D(nums)] = true;
            q.push({D(nums),temp+'D'});
        }
        if(!visited[S(nums)])
        {
            visited[S(nums)] = true;
            q.push({S(nums),temp+'S'});
        }
        if(!visited[L(nums)])
        {
            visited[L(nums)] = true;
            q.push({L(nums),temp+'L'});
        }
        if(!visited[R(nums)])
        {
            visited[R(nums)] = true;
            q.push({R(nums),temp+'R'});
        }
    }
    return "-1";
}
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    for(int i=0; i<t; ++i)
    {
        int a, b;
        cin >> a >> b;
        cout << BFS(a, b) << '\n';
    }
    return 0;
}