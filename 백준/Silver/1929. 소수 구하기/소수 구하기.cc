#include <iostream>
#include <cmath>
using namespace std;
int main ()
{
    int n,m;
    scanf("%d %d", &n, &m);
    bool* primes = new bool[m + 1]();
    primes[1] = true;
    
    for(int i=2; i<= sqrt(m); ++i)
    {
        if(!primes[i])
        {
            for(int j=i*2; j<=m; j+=i)
            {
                primes[j] = true;
            }
        }
    }
    for(int i=n; i<=m; i++)
    {
        if(!primes[i])printf("%d\n", i);
    }
    return 0;
}