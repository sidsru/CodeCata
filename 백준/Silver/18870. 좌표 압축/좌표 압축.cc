#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
    int n, num;
    cin >> n;
    vector<int> nums;
    map<int,int> compnum;
    for(int i=0; i<n; i++)
    {
        cin >> num;
        nums.push_back(num);
        
    }
    vector<int> temp(nums);
    sort(temp.begin(), temp.end());
    temp.erase(unique(temp.begin(), temp.end()), temp.end());
    
    for(int i=0; i < temp.size(); i++)
    {
        compnum.insert({temp[i], i});
    }
    
    for(int j=0; j < nums.size(); j++)
    {
        cout << compnum[nums[j]] << " ";
    }
}