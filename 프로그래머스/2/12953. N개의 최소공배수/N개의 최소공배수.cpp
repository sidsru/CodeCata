#include <string>
#include <vector>

using namespace std;

int Gcd(int a, int b)
{
    int r = a % b;
    if(r == 0) return b;
    return Gcd(b, r);
}

int Lcm(int a, int b)
{
    return (a * b) / Gcd(a, b);
}

int solution(vector<int> arr) {
    int answer = 0;
    int temp = arr[0];
    for (int i=1; i < arr.size(); i++)
    {
        temp = Lcm(temp, arr[i]);
    }
    answer = temp;
    return answer;
}