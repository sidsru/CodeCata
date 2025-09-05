#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

bool prime(int n)
{
	for(int i = 2; i <= sqrt(n); i++)
    {
    	if(n%i == 0) return false;
    }
    return true;
}

int solution(vector<int> nums) {
    int answer = 0;
    int sum = 0;
    // 최대 50개의 수가 주어짐 각 원소는 1000이하의 수로 이루어져있음
    // 서로 다른 3개를 골라 더했을 경우 소수가 되는 경우를 출력하여라
    // 중복되는 숫자는 주어지지 않는다
    // 방법 1: sort함수를 이용해 정렬한다음 무작위로 3개의 숫자를 더한다 더했을때 answer에 스택을 하나 쌓아줌
    for(int i=0; i<nums.size(); i++)
    {
        for(int j=i+1; j<nums.size(); j++)
        {
            for(int k=j+1; k<nums.size(); k++)
            {
                if(prime(nums[i]+nums[j]+nums[k])) ++answer;
            }
        }
    }
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;

    return answer;
}