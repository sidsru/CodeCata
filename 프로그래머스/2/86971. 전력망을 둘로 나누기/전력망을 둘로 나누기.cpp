#include <string>
#include <vector>
#include <queue>
//#include <iostream>

using namespace std;
int cnt;
vector<vector<int>> info(101);

inline int Min(int a, int b)
{
    return a < b ? a : b;
}
inline int ABS(int a, int n)
{
    return a > n ? a - n : n - a;
}

void DFS(int a, int b)
{
    vector<bool> bis(101);
    bis[a] = true;
    bis[b] = true;
    queue<int> q;
    q.push(a);
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        for(int i=0; i<info[node].size();i++)
        {
            int node2 = info[node][i];
            if(bis[node2])
                continue;
            ++cnt;
            q.push(node2);
            bis[node2] = true;
        }
    }
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 101;
    for(int i=0; i<wires.size(); i++)
    {
        info[wires[i][0]].push_back(wires[i][1]);
        info[wires[i][1]].push_back(wires[i][0]);
    }
    for(auto w : wires)
    {
        cnt = 1;
        int a = w[0];
        int b = w[1];
        DFS(a, b);
        answer = Min(answer, ABS(cnt*2, n));
        //cout << ABS(cnt*2, n) << '\n';
    }
    return answer;
}