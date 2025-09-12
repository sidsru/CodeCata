#include <string>
#include <vector>
#include <algorithm>

int student[32];
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    for(int& a : lost)
    {
        student[a]--;
    }
    
    for(int& a : reserve)
    {
        student[a]++;
    }
    
   for(int i=1; i<=n; i++)
   {
       if(student[i] == -1)
       {
           if(student[i-1] == 1)
           {
               student[i-1] = 0;
               student[i] = 0;
           }
           else if(student[i+1] == 1)
           {
               student[i+1] = 0;
               student[i] = 0;
           }
       }
       if(student[i] >= 0)
           ++answer;
   }
    return answer;
}