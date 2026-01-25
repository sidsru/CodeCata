// 백준
#include <iostream>
#define endl '\n'
using namespace std;
constexpr int INF = (~0U >> 1);

int R, C;
bool visited[26];
string s[20];
int xmove[4] = { 0,0,1,-1 };
int ymove[4] = { 1,-1,0,0 };
int Max;
inline bool check(const int x, const int y)
{
	return (x < 0 || y < 0 || R <= x || C <= y);
}
void DFS(const int x, const int y, const int cnt)
{
	if (Max < cnt)
	{
		Max = cnt;
	}
	for (int i = 0; i < 4; ++i)
	{
		int xx = xmove[i] + x;
		int yy = ymove[i] + y;
		if (check(xx, yy))
			continue;
		if (visited[s[xx][yy] - 'A'])
			continue;
		visited[s[xx][yy] - 'A'] = true;
		DFS(xx, yy, cnt + 1);
		visited[s[xx][yy] - 'A'] = false;
	}
}
void Input()
{
	cin >> R >> C;
	for (int i = 0; i < R; ++i)
	{
		cin >> s[i];
	}
	visited[s[0][0] - 'A'] = true;
	DFS(0, 0, 1);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	Input();
	cout << Max;
	return 0;
}
