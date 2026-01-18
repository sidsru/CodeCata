// 백준
#include <iostream>
#include <queue>
#define endl '\n'
using namespace std;


bool visited[100001] = { false };

int BFS(const int start, const int target)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0 ,target });
	while (!pq.empty())
	{
		int cnt = pq.top().first;
		int now = pq.top().second;
		pq.pop();
		visited[now] = true;
		if (now == start)
		{
			return cnt;
		}
		if (now - 1 >= 0 && !visited[now - 1])
		{
			pq.push({ cnt + 1, now - 1 });
		}		
		if (now + 1 <= 100000 && !visited[now + 1])
		{
			pq.push({ cnt + 1, now + 1 });
		}
		if (now & 1)
		{
			continue;
		}
		if (now >> 1 >= 0 && !visited[now >> 1])
		{
			pq.push({ cnt , now >> 1 });
		}
	}
	return -1;
}

void Input()
{
	int n, m;
	cin >> n >> m;
	cout << BFS(n, m);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	Input();
	return 0;
}
