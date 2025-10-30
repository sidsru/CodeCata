#include <iostream>
#include <algorithm>
using namespace std;

long long p(long long a)
{
    return a * a;
}

int main()
{
    int a[3];
    while(1)
    {
        for(int i=0; i<3; i++)
        {
            cin >> a[i];
        }
        sort(a, a+3);
        if(a[0] == 0) break;
        if(p(a[0]) + p(a[1]) == p(a[2])) cout << "right" << "\n";
        else cout << "wrong" << "\n";
    }
    return 0;
}