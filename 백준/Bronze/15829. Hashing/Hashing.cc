#include<iostream>
using namespace std;
long long square(long long n, int i)
{
    for(int j=0; j<i; j++)
    {
        n *= 31;
        n %= 1234567891;
    }
    return n;
}
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long l,sum = 0;
    cin >> l;
    string s;
    cin >> s;
    for(int i=0; i< l; i++)
    {
        sum += square((s[i]-'a')+1, i);
    }
    cout << sum;
}