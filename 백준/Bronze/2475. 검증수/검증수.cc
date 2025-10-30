#include <iostream>
using namespace std;
int p(int a)
{
    return a*a;
}
int main ()
{
    int n,sum = 0;
    for(int i=0; i<5; i++)
    {
        cin >> n;
        sum += p(n);
    }
    cout << sum % 10;
}