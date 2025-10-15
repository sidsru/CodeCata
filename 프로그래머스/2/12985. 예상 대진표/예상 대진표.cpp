#include <iostream>
#include <cmath>
using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;
    float A = a;
    float B = b;
    
    while(A != B)
    {
        A = ceil(A/2);
        B = ceil(B/2);
        
        ++answer;
    }
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << answer << endl;

    return answer;
}