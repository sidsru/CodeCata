#include<iostream>
using namespace std;

int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int l;
    long long r = 1,sum = 0, m = 1234567891;
    cin >> l;
    string s;
    cin >> s;
    for(int i=0; i< l; i++)
    {
        sum += ((int)(s[i]-'a'+1) * r) % m;
        r = (r*31) % m;
    }
    cout << sum % m;
}