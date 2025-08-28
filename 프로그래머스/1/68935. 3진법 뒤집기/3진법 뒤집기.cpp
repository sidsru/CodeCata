#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int>arr;
    while(n != 0)
    {
        //3으로 나누고 나머지를 푸쉬백
        arr.push_back(n%3);
        n /= 3;
    }
    int expon = 1;
    for(int i=1; i<=arr.size(); i++)
    {
        answer += arr[arr.size()-i] * expon;
        expon *= 3;
    }
    return answer;
}