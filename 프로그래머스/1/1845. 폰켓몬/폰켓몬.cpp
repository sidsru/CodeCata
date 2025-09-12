#include <vector>
#include <set>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    set<int>po(nums.begin(), nums.end());
    answer = po.size();
    if (answer > nums.size()/2)
    {
        answer = nums.size()/2;
    }
    //연구실에 있는 포켓몬의 절반을 가져갈수 있음
    //다만 같은 종류의 포켓몬은 2마리만 가져갈 수 있음
    return answer;
}