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
    int temp[4] = {0,0,0,0};
    int answer = 0;
    for(int i=3; i>=0; --i)
    {
        temp[i] = n%10;
        n /= 10;
    }
    for(int i=1;i<4; ++i)
    {
        answer += temp[i];
        answer *= 10;
    }
    answer += temp[0];
    return answer;
}
inline int R(int n)
{
    int temp[4] = {0,0,0,0};
    int answer = 0;
    for(int i=3; i>=0; --i)
    {
        temp[i] = n%10;
        n /= 10;
    }
    answer += temp[3];
    for(int i=0;i<3; ++i)
    {
        answer *= 10;
        answer += temp[i];
    }
    return answer;
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