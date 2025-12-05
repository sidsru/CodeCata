#include <string>
#include <vector>

using namespace std;
int GCD(int a, int b)
{
    if(b == 0)
        return a;
    return GCD(b, a%b);
}
inline int Max(const int& a, const int& b)
{
    return a > b ? a : b;
}
int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    int gcd1 = arrayA[0];
    int gcd2 = arrayB[0];
    
    for(int i=1; i<arrayA.size(); ++i)
        gcd1 = GCD(gcd1, arrayA[i]);    
    for(int i=1; i<arrayB.size(); ++i)
        gcd2 = GCD(gcd2, arrayB[i]);
    
    for(int a : arrayA)
        if(a % gcd2 == 0)
        {
            gcd2 = 0;
            break;
        }
            
    for(int b : arrayB)
        if(b % gcd1 == 0)
        {
            gcd1 = 0;
            break;
        }
            
    return answer = Max(gcd1, gcd2);
}