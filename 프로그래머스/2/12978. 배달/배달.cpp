#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int>dist;
vector<pair<int,int>> map[51];

void Dijkstra(int n)
{
    priority_queue<pair<int,int>> pq;
    pq.push(make_pair(0,1));
    dist[1] = 0;
    
    while(!pq.empty())
    {
        int cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        
        for(int i=0; i<map[cur].size();i++)
        {
            int next = map[cur][i].first;
            int ncost = map[cur][i].second;
            
            if(dist[next] > cost + ncost)
            {
                dist[next] = cost + ncost;
                pq.push(make_pair(dist[next], next));
            }
        }
    }
}

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    dist.resize(N+1, 2e9);
    for(int i=0; i< road.size(); i++)
    {
        int n1 = road[i][0];
        int n2 = road[i][1];
        int cost = road[i][2];
        
        map[n1].push_back({n2, cost});
        map[n2].push_back({n1, cost});
    }
    
    Dijkstra(N);
    
    for(int i=1; i<=N; i++)
    {
        if (dist[i] <= K)
            answer++;
    }
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    //cout << "Hello Cpp" << endl;

    return answer;
}