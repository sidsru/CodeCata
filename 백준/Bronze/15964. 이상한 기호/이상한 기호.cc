#include <iostream>
using namespace std;
int function(int a, int b)
{
    return (a+b)*(a-b);
}
int main()
{
    int a, b;
    cin >> a >> b;
    cout << function(a, b);
}