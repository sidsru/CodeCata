#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;
bool findprime(int a)
{
    if(a < 2) return false;
    for(int i=2; i<= sqrt(a); i++)
    {
        if(a%i == 0) 
            return false; 
    }
    return true;
}
int solution(string numbers) {
    int answer = 0;
    set<int> ans;
    sort(numbers.begin(), numbers.end());
    do
    {
        string temp = "";
        for (int i=0; i < numbers.size(); i++)
        {
            temp += numbers[i];
            if(findprime(stoi(temp)))
                ans.insert(stoi(temp));
        }
    }while(next_permutation(numbers.begin(), numbers.end()));
    
    return answer = ans.size();
}