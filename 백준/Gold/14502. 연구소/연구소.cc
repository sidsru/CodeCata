// 백준
#include <iostream>
#include <queue>
#include <cstring>
#define endl '\n'
using namespace std;
constexpr int INF = (~0U >> 1);
int n, m, answer = 0;
int maps[8][8];
int temp[8][8];
queue<pair<int, int>> virus;
vector<pair<int, int>> None, Wall;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
bool check[64];

static inline bool checkRange(const int x, const int y)
{
	return (x < 0 || x >= n || y < 0 || y >= m);
}
int BFS()
{
	queue<pair<int, int >> q = virus;
	memcpy(temp, maps, sizeof(maps));
	while (!q.empty())
	{
		pair<int, int> cur = q.front();
		temp[cur.first][cur.second] = 2;
		q.pop();

		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];
			if (checkRange(nx, ny))
				continue;
			if (temp[nx][ny] == 0)
			{
				temp[nx][ny] = 2;
				q.push({ nx, ny });
			}
		}
	}
	int safe = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (temp[i][j] == 0)
				safe++;
		}
	}
	return safe;
}

void DFS(const int cnt, const int index)
{
	if (cnt == 3)
	{
		for (int i = 0; i < None.size(); i++)
		{
			if (check[i])
			{
				Wall.push_back({ None[i] });
			}
		}
		for (int i = 0; i < Wall.size(); i++)
		{
			maps[Wall[i].first][Wall[i].second] = 1;
		}
		int size = BFS();
		answer = max(answer, size);
		for (int i = 0; i < Wall.size(); i++)
		{
			maps[Wall[i].first][Wall[i].second] = 0;
		}
		Wall.clear();
	}
	else
	{
		for (int i = index; i < None.size(); i++)
		{
			if (!check[i])
			{
				check[i] = true;
				DFS(cnt + 1, i);
				check[i] = false;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> maps[i][j];
			if (maps[i][j] == 0)
				None.push_back({ i, j });
			else if (maps[i][j] == 2)
				virus.push({ i, j });
		}
	}
	DFS(0, 0);
	cout << answer;
	return 0;
}
