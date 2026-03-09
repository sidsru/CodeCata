// 백준
#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#define endl '\n'
using namespace std;
constexpr int INF = (~0U >> 1);

int n;
int map[21][21];
bool visited[20][20];
int xmove[4] = { -1,0,0, 1 };
int ymove[4] = { 0,-1,1, 0 };
pair<int, int> shark;
int sharksize = 2;
int eatcount = 0;
int second = 0;
bool check(const int x, const int y)
{
	return (x < 0 || n <= x || y < 0 || n <= y);
}
bool BFS(const pair<int, int>& start)
{
	memset(visited, 0, sizeof(visited));
	queue<pair<pair<int, int>, int>> q;
	q.push(make_pair(start, 0));
	visited[start.first][start.second] = true;
	vector<pair<int, int>> v;
	int targetcost = INF;
	while (q.empty() == false)
	{
		int x = q.front().first.first;
		int y = q.front().first.second;
		int cost = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int xx = x + xmove[i];
			int yy = y + ymove[i];
			int ncost = cost + 1;
			if (check(xx, yy))
				continue;
			if (visited[xx][yy] == true)
				continue;
			if (map[xx][yy] > sharksize)
				continue;
			if (map[xx][yy] != 0 && map[xx][yy] < sharksize)
			{
				if (ncost <= targetcost)
				{
					targetcost = ncost;
					v.push_back(make_pair( xx, yy ));
				}
			}
			visited[xx][yy] = true;
			q.push(make_pair(make_pair(xx, yy), ncost));
		}
	}
	if (v.empty())
		return false;

	sort(v.begin(), v.end());

	pair<int, int > now = v[0];

	map[now.first][now.second] = 0;
	second += targetcost;
	shark = now;
	return true;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 9)
			{
				shark = make_pair(i, j);
				map[i][j] = 0;
			}
		}
	}
	while (BFS(shark))
	{
		++eatcount;
		if (eatcount == sharksize)
		{
			++sharksize;
			eatcount = 0;
		}
	}
	cout << second;
	return 0;
}
