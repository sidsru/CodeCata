// 백준
#include <iostream>
#include <queue>
#define endl '\n'
using namespace std;
constexpr int INF = (~0U >> 1);
int r, c, t;
int map[50][50];
enum : int
{
	Up = 0,
	Down = 1
};
int purifier[2]{};
bool check(const int x, const int y)
{
	return (x < 0 || y < 0 || r <= x || c <= y);
}
void Diffusion()
{

	queue<pair<int, pair<int, int>>> q;
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			if (map[i][j] > 0)
			{
				int Amount = map[i][j] / 5;
				q.push(make_pair(Amount, make_pair(i,j)));
			}
		}
	}
	int directions[4][2] = { { -1,0 },{ 1,0 },{ 0,-1 },{ 0,1 } };
	while (!q.empty())
	{
		int Amount = q.front().first;
		int x = q.front().second.first;
		int y = q.front().second.second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + directions[i][0];
			int ny = y + directions[i][1];
			if (check(nx, ny) || map[nx][ny] == -1)
				continue;
			map[x][y] -= Amount;
			map[nx][ny] += Amount;
		}
	}
}
void UpCycle()
{
	int x = purifier[Up] - 1;
	int y = 0;
	while (x > 0)
	{
		map[x][y] = map[x - 1][y];
		x--;
	}
	while (y < c - 1)
	{
		map[x][y] = map[x][y + 1];
		y++;
	}
	while (x < purifier[Up])
	{
		map[x][y] = map[x + 1][y];
		x++;
	}
	while (y > 0)
	{
		map[x][y] = map[x][y - 1];
		y--;
	}
	map[purifier[Up]][1] = 0;
}

void DownCycle()
{
	int x = purifier[Down] + 1;
	int y = 0;
	while (x < r - 1)
	{
		map[x][y] = map[x + 1][y];
		x++;
	}
	while (y < c - 1)
	{
		map[x][y] = map[x][y + 1];
		y++;
	}
	while (x > purifier[Down])
	{
		map[x][y] = map[x - 1][y];
		x--;
	}
	while (y > 0)
	{
		map[x][y] = map[x][y - 1];
		y--;
	}
	map[purifier[Down]][1] = 0;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> r >> c >> t;

	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			cin >> map[i][j];
			if (map[i][j] == -1)
			{
				if (purifier[Up] == 0)
				{
					purifier[Up] = i;
				}
				else
				{
					purifier[Down] = i;
				}
			}
		}
	}
	for (int i = 0; i < t; ++i)
	{
		Diffusion();
		UpCycle();
		DownCycle();
	}
	int sum = 0;
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			if (map[i][j] > 0)
			{
				sum += map[i][j];
			}
		}
	}
	cout << sum << endl;
	return 0;
}
