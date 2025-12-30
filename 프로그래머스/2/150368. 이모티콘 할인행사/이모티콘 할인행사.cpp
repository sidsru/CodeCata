#include <string>
#include <vector>

using namespace std;

int DC[4] = {10, 20, 30, 40};
vector<pair<int, int>> price(7,{0,0});
vector<int> answer(2);
void DFS(const vector<vector<int>>& users, const vector<int>& emoticons,const int depth)
{
    if(depth == emoticons.size())
    {
        int sup = 0, sum = 0;
        for(int i=0; i < users.size(); ++i)
        {
            int total = 0;
            for(int j=0; j < emoticons.size(); ++j)
            {
                if(users[i][0] <= price[j].second)
                {
                    total += price[j].first;
                }
            }
            if(users[i][1] <= total)
            {
                ++sup;
            }
            else
            {
                sum += total;
            }
        }
        if(sup > answer[0])
        {
            answer[0] = sup;
            answer[1] = sum;
        }
        else if(sup == answer[0])
        {
            if(answer[1] < sum)
            {
                answer[1] = sum;
            }
        }
    }
    else
    {
        for(int i=0; i<4; ++i)
        {
            price[depth].first = (100 - DC[i]) * emoticons[depth] / 100;
            price[depth].second = DC[i];
            DFS(users, emoticons, depth+1);
        }
    }
    return;
}
vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    DFS(users, emoticons, 0);
    return answer;
}