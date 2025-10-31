#include <iostream>
using namespace std;
int gcd(int a, int b) // 최대 공약수
{
    if(b == 0)return a;
    return gcd(b, a % b);
}
int lcm(int a, int b) // 최소 공배수
{
    return a*b / gcd(a,b);
}
int main()
{
    int a, b;
    cin >> a >> b;
    cout << gcd(a, b) << "\n" << lcm(a, b);
}