// 백준
#include <iostream>
#include <queue>
#define endl '\n'
using namespace std;
constexpr int INF = (~0U >> 1);
int n, m;
int arr[100][100];
int movex[4] = { 1, -1, 0, 0 };
int movey[4] = { 0, 0,1,-1 };
int answer = 0;
bool check(const int x, const int y)
{
	return (x < 0 || n <= x || y < 0 || m <= y);
}
queue<pair<int, int>> q;
bool BFS()
{
	int visited[100][100] = {};
	int cnt = 0;
	q.push(make_pair(0, 0));
	visited[0][0] = 1;
	while (q.empty() == false)
	{

		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + movex[i];
			int ny = y + movey[i];
			if (check(nx, ny) == true)
			{
				continue;
			}
			if (arr[nx][ny] == 1)
			{
				++visited[nx][ny];
				if (visited[nx][ny] >= 2)
				{
					arr[nx][ny] = 0;
					++cnt;
				}
			}
			if (arr[nx][ny] == 0)
			{
				if (visited[nx][ny] == 0)
				{
					visited[nx][ny] = 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
	if (cnt > 0)
	{
		return true;
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}
	while (BFS() == true)
	{
		++answer;
	}
	cout << answer << endl;
	return 0;
}
