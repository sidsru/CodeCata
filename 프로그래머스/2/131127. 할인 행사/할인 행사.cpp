#include <string>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    map<string, int> w;
    for(int i=0; i < want.size(); i++)
    {
        w[want[i]] = {number[i]};
    }
    /*for(auto& a : w)
    {
        cout << a.first << " " << a.second << endl;
    }
    cout << endl;*/
    
    for(int i=0;i<=discount.size()-10; i++)
    {
        map<string, int> temp = w;
        for(int j=i; j < i+10; j++)
        {
            if(temp.find(discount[j]) != temp.end() && temp[discount[j]] > 0)
            {
                --temp[discount[j]];
                //cout << discount[j+i] << " " <<temp[discount[j+i]] << endl;
            }
        }
        /*for(auto& a : temp)
        {
            cout << a.first << " " << a.second << endl;
        }
        cout << endl;*/
        int sum = 0;
        for(auto& a : temp)
        {
            sum += a.second;
            //cout << a.first << " " << a.second << " " << endl;
        }
        if(sum == 0)
        {
            ++answer;
        }
    }
    return answer;
}