#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    int n,count;
    cin >> n;
    int nums[10001] = {0};
    for(int i=0; i<n; i++)
    {
        cin >> count;
        nums[count]++;
        //scanf("&d", num[i]);
    }
    for(int i=0; i<10001; i++)
    {
        for(int j=0; j<nums[i]; j++)
        {
            cout << i << "\n";
        }
    }
    /*sort(nums.begin(), nums.end());
    for(int& a : nums)
    {
        cout << a << "\n";
        //printf("%d\n", a);
    }*/
}