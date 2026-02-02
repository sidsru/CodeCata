// 백준
#include <iostream>
#include <queue>
#define endl '\n'
using namespace std;
constexpr int INF = (~0U >> 1);
int Min = INF;
int answer = 0;

void BFS(const int start, const int end)
{
	bool visited[100001] = {};
	queue<pair<int, int>> q;
	q.push({ start,0 });
	visited[start] = true;
	while (!q.empty())
	{
		visited[end] = false;
		int now = q.front().first;
		int cnt = q.front().second;
		q.pop();
		visited[now] = true;
		if (Min < cnt)
			break;
		if (end == now)
		{
			if (Min > cnt)
			{
				Min = cnt;
				answer = 1;
			}
			else if (Min == cnt)
			{
				answer++;
			}
		}
		int next[3] = { now + 1, now - 1, now << 1 };
		for (int i = 0; i < 3; ++i)
		{
			if (next[i] < 0 || next[i] >100000)
				continue;
			if (visited[next[i]])
				continue;

			q.push({ next[i], cnt + 1 });
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, k;
	cin >> n >> k;
	BFS(n, k);
	cout << Min << endl << answer;
	return 0;
}
