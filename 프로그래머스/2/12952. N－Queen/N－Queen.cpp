#include <string>
#include <vector>
#include <cmath>
int arr[12], ans;
using namespace std;
bool check(const int x)
{
    for(int i=0; i<x; ++i)
    {
        if(arr[i] == arr[x] || abs(arr[x] - arr[i]) == x - i)
            return false;
    }
    return true;
}
void queen(const int n, int x)
{
    if(n == x)
    {
        ++ans;
        return;
    }
        
    for(int i=0; i<n; ++i)
    {
        arr[x] = i;
        if(check(x))
            queen(n, x+1);
    }
}
int solution(int n) {
    queen(n, 0);
    return ans;
}