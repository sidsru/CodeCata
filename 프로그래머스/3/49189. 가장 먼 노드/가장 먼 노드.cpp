// 프로그레머스
#include <string>
#include <vector>
#include <queue>

using namespace std;
bool visited[20001];
int answer = 0, Max = 0;
void BFS(const vector<vector<int>>& v)
{
	queue<pair<int, int>> q;
	q.push({ 1, 0 });
	visited[1] = true;
	while (!q.empty())
	{
		int node = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if (cnt > Max)
		{
			answer = 1;
			Max = cnt;
		}
		else if (Max == cnt)
		{
			++answer;
		}
		for (int i = 0; i < v[node].size(); ++i)
		{
			if (visited[v[node][i]])
				continue;
			visited[v[node][i]] = true;
			q.push({ v[node][i], cnt + 1 });
		}
	}
}
int solution(int n, vector<vector<int>> edge) {
	vector<vector<int>> v;
	v.push_back(vector<int>());
	for (int i = 1; i <= edge.size(); ++i)
	{
		v.push_back(vector<int>());
	}
	for (vector<int> e : edge)
	{
		v[e[0]].push_back(e[1]);
		v[e[1]].push_back(e[0]);
	}
	BFS(v);
	return answer;
}