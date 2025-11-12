#include <string>
#include <queue>

using namespace std;

int solution(int x, int y, int n) {
    queue<pair<int,int>> nums;
    nums.push({y,0});
    while(!nums.empty())
    {
        int val = nums.front().first;
        int count = nums.front().second;
        nums.pop();
        if(val == x) return count;
        
        if(val % 2 == 0)
            nums.push({val/2, count+1});
        
        if(val % 3 == 0)
            nums.push({val/3, count+1});
        
        if(val - n >= x)
            nums.push({val-n, count+1});
    }
    return -1;
}