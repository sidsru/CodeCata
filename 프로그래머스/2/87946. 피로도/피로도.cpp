#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    
    sort(dungeons.begin(), dungeons.end());
    do{
        int cnt = k;
        int a = 0;
        for(int i=0; i<dungeons.size(); i++)
        {
            if(cnt <dungeons[i][0]) break;
            cnt -= dungeons[i][1];
            a++;
        }
        if(answer<a) answer = a;
        if(answer == dungeons.size()) break;
    }while(next_permutation(dungeons.begin(),dungeons.end()));
    
    return answer;
}