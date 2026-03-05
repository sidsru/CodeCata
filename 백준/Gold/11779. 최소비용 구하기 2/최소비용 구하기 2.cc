// 백준
#include <iostream>
#include <queue>
#define endl '\n'
using namespace std;
constexpr int INF = (~0U >> 1);
int n, m;
int dist[1001];
int line[1001];
bool visited[1001];
vector<pair<int, int>> v[1001];
vector<int> answerv;

void Dijkstra(const int start, const int end)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.emplace(0, start);
    dist[start] = 0;
    while (pq.empty() == false)
    {
        int cost = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        if (visited[node] == true)
        {
            continue;
        }
        visited[node] = true;
        
        for (int i = 0; i < v[node].size(); i++)
        {
            int NextCost = v[node][i].first;
            int NextNode = v[node][i].second;

            if (dist[NextNode] > cost + NextCost)
            {
                dist[NextNode] = cost + NextCost;
                line[NextNode] = node;
                pq.emplace(cost + NextCost, NextNode);
            }
        }
    }
    cout << dist[end] << endl;
    int temp = end;
    while (temp)
    {
        answerv.push_back(temp);
        temp = line[temp];
    }
    cout << answerv.size() << endl;
    for (int i = answerv.size()-1; i >= 0 ; i--)
    {
        cout << answerv[i] << " ";
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    cin >> m;
    for (int i = 1; i <= n; i++)
    {
        dist[i] = INF;
    }
    for (int i = 0; i < m; i++)
    {
        int from, to, cost;
        cin >> from >> to >> cost;
        v[from].emplace_back(cost, to);
    }
    int start, end;
    cin >> start >> end;

    Dijkstra(start, end);
    return 0;
}
