#include <string>
#include <vector>

using namespace std;
int ans = 0;
vector<int> answer = { -1 };
int arr[11] = { 10,9,8,7,6,5,4,3,2,1,0 };
void DFS(const int cnt,const int n, const vector<int>& info, vector<int>& v, const int index)
{
    if (n == cnt)
    {
        int res = 0;
        for (int i = 0; i < 11; ++i)
        {
            if (v[i] > info[i])
            {
                res += arr[i];
            }
            else if (info[i])
            {
                res -= arr[i];
            }
        }
        if (res > ans)
        {
            ans = res;
            answer = v;
        }
        else if (res == ans && res)
        {
            for (int i = 10; i >= 0; --i)
            {
                if (answer[i] > v[i])
                {
                    return;
                }
                else if (answer[i] < v[i])
                {
                    answer = v;
                    break;
                }
            }
        }
        return;
    }
    for (int i = index; i < 11; ++i)
    {
        int num = info[i]+1;
        if ( num > n -cnt )
        {
            num = n - cnt;
        }
        v[i] = num;
        DFS(cnt+ num, n, info, v, i+1);
        v[i] = 0;
    }
    return;
}
vector<int> solution(int n, vector<int> info) {
    vector<int> v(11, 0);
    DFS(0 ,n, info, v, 0);
    return answer;
}