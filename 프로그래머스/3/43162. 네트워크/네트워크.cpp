// 프로그레머스
#include <string>
#include <vector>
#include <queue>

using namespace std;

bool visited[201];

int BFS(const vector<vector<int>>& computers, const int network)
{
	if (visited[network])
	{
		return 0;
	}
	queue<int> q;
	q.push(network);
	visited[network] = true;
	while (!q.empty())
	{
		int computer = q.front();
		q.pop();
		for (int i = 0; i < computers[computer].size(); ++i)
		{
			if (visited[i])
			{
				continue;
			}
			if (computers[computer][i] == 0)
			{
				continue;
			}
			visited[i] = true;
			q.push(i);
		}
	}
	return 1;
}
int solution(int n, vector<vector<int>> computers) {
	int answer = 0;
	for (int i = 0; i < n; ++i)
	{
		answer += BFS(computers, i);
	}
	return answer;
}