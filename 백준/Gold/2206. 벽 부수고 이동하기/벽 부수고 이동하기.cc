// 백준
#include <iostream>
#include <string>
#include <queue>
#define endl '\n'
using namespace std;
constexpr int INF = (~0U >> 1);

int n, m;
int xmove[4] = { 1,-1,0,0 };
int ymove[4] = { 0,0,1,-1 };
int map[1001][1001];
bool visited[1001][1001][2] = { false };
struct Move
{
	Move(pair<int, int> xy, int cnt, bool wall) : xy(xy), cnt(cnt), wall(wall)
	{

	}
	pair<int, int> xy;
	int cnt;
	bool wall;
};
bool check(const int x, const int y)
{
	return (x < 0 || n <= x || y < 0 || m <= y);
}
int BFS(const pair<int, int> start, const pair<int, int> end)
{
	queue<Move> q;
	Move move(start, 1, false);
	q.push(move);
	visited[start.first][start.second][0] = true;
	while (q.empty() == false)
	{
		int x = q.front().xy.first;
		int y = q.front().xy.second;
		int cnt = q.front().cnt;
		bool wall = q.front().wall;
		q.pop();
		if (x == end.first && y == end.second)
		{
			return cnt;
		}
		for (int i = 0; i < 4; i++)
		{
			int nx = x + xmove[i];
			int ny = y + ymove[i];
			if (check(nx, ny) == true)
			{
				continue;
			}

			Move temp(make_pair(nx, ny), cnt + 1, wall);
			if (map[nx][ny] == 1)
			{
				if (wall == false)
				{
					if (visited[nx][ny][1] == true)
					{
						continue;
					}
					temp.wall = true;
					visited[nx][ny][1] = true;
					q.push(temp);
				}
				continue;
			}

			if (visited[nx][ny][wall] == true)
			{
				continue;
			}
			visited[nx][ny][wall] = true;
			q.push(temp);
		}
	}
	return -1;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < m; j++)
		{
			map[i][j] = s[j] - '0';
		}
	}
	int answer = BFS(make_pair(0, 0), make_pair(n - 1, m - 1));
	cout << answer;
	return 0;
}
