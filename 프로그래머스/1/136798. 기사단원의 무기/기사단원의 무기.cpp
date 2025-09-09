#include <string>
#include <vector>
#include <set>
#include <cmath>
using namespace std;
int yaksu(int num)
{
    set<int> sumyaksu, vyaksu;
    int sqrtnum = sqrt(num);
    for(int i=1; i<=sqrtnum; i++)
    {
        if(num%i == 0)
        {
            vyaksu.insert(i);
        }
    }
    sumyaksu = vyaksu;
    for(auto it : vyaksu)
    {
        sumyaksu.insert(num/it);
    }
    return sumyaksu.size();
}
            
int solution(int number, int limit, int power) {
    int answer = 0;
    int temp = 0;
    
    
    for(int i=1; i<=number; i++)
    {
        temp = yaksu(i);
        if(temp > limit)
        {
            temp = power;
        }
        answer += temp;
    }
    
    return answer;
}