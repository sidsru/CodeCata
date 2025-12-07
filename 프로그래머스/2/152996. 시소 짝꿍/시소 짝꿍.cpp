#include <vector>
#include <map>

using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;
    map<long long, long long> m;
    
    for(long long  a : weights)
        ++m[a];
    
    for(pair<long long, long long>  p : m)
    {
        long long w = p.first;
        long long c = p.second;
        
        if(c >= 2)
            answer +=  c*(c-1) / 2;
        
        if(w * 3 % 2 == 0)
            if(m.find(w * 3 / 2) != m.end())
                answer += m[w * 3 / 2] * c;     
        
        if(w * 4 % 2 == 0)
            if(m.find(w * 4 / 2) != m.end())
                answer += m[w * 4 / 2] * c;
               
        if(w * 4 % 3 == 0)
            if(m.find(w * 4 / 3) != m.end())
                answer += m[w * 4 / 3] * c;
    }
    return answer;
}