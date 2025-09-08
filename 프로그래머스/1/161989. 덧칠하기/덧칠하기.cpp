#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    // 1m길이의 n개의 벽을 길이 m의 롤러로 삐져나오지 않게 칠한다
    // 한번에 m의 길이로 칠하고 1m가 될때 까지 칠한다
    // 다시 칠하기로 정한 벡터가 들어오며 최소한 얼마큼의 롤러를 사용을 해야 구역을 다 칠할수 있는지 구하라
    
    // 가장 먼저 최소한에 for문을 벡터의 사이즈 - m 만큼 시행
    // 백터의 시작점부터 시행함
    int sections = 0;
    
    for(auto a : section)
    {
        if(sections > a ) continue;
        ++answer;
        sections = a + m;
    }
    // 왜 틀렸지 예외 처리를 안한것이 있을텐데 예외 처리가 무엇이 있을까?
    // 작동방식을 다시 생각해보자
    // 만약 섹션이 중간에 칠해야 하는부분이 많이 떨어져있다면?
    // 1~n의 길이구역이 있다? 이걸 생각 안해봤네
    // 존재의 이유? 벽에서 벗어나면 안된다고? 
    // 
    
    return answer;
}