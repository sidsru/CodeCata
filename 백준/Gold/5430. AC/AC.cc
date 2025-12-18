#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;
void adddq(deque<string>& dq, const string& nums)
{
    string temp = "";
    for(int i = 1; i < nums.size(); ++i)
    {
        if(nums[i] == ',' || nums[i] == ']')
        {
            if(temp.size()>0)
                dq.push_back(temp);
            temp = "";
        }
        else
        {
            temp += nums[i];
        }
    }
}
void printtarget(deque<string>& dq, const int d, const bool bIsflag, const int num)
{
    if(d > num)
    {
        cout << "error\n";
        return;
    }
            
    if(bIsflag)
        reverse(dq.begin(),dq.end());
    cout << '[' ;
    for(int i=0; i<dq.size(); ++i)
    {
        cout << dq[i];
        if(i != dq.size()-1)
            cout << ",";
    }
    cout << "]\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int T;
    cin >> T;
    for(int i=0; i<T; ++i)
    {
        int num;
        string s, nums, temp = "";
        deque<string> dq;
        cin >> s >> num >> nums;

        adddq(dq, nums);
        
        int d = 0;
        bool bIsflag = false;
        
        for(int j=0; j<s.size(); ++j)
        {
            if(s[j] == 'R')
            {
                if(bIsflag)
                    bIsflag = false;
                else
                    bIsflag = true;
            }
            else if(s[j] == 'D')
            {
                ++d;
                if(dq.empty())
                    continue;
                if(!bIsflag)
                    dq.pop_front();
                else
                    dq.pop_back();
            }
        }
        printtarget(dq, d, bIsflag, num);
    }
    return 0;
}