// 프로그레머스
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
bool visited[51];
using namespace std;
bool check(const string& a, const string& b)
{
    int cnt = 0;
    for (int i = 0; i < a.size(); ++i)
    {
        if (a[i] != b[i])
        {
            ++cnt;
        }
        if (cnt > 1)
        {
            return false;
        }
    }
    if (cnt == 0)
    {
        return false;
    }
    return true;
}
int BFS(const string& begin, const string& target, const vector<string>& words)
{
    queue<pair<int, int>> q;
    int t = -1;
    for (int i = 0; i < words.size(); ++i)
    {
        if (words[i] == target)
        {
            t = i;
            break;
        }
    }
    if (t == -1)
    {
        return 0;
    }
    q.push({t , 1});
    while (!q.empty())
    {
        int index = q.front().first;
        int cnt = q.front().second;
        q.pop();
        visited[index] = true;

        if (check(words[index], begin))
        {
            return cnt;
        }
        for (int i = 0; i < words.size(); ++i)
        {
            if (visited[i])
            {
                continue;
            }
            if (check(words[i], words[index]))
            {
                visited[i] = true;
                q.push({i, cnt+1});
            }
        }
    }
    return 0;
}
int solution(string begin, string target, vector<string> words) {
    int answer = BFS(begin, target, words);
    return answer;
}