#include <iostream>
#include <stack>
using namespace std;

int main ()
{
    int k;
    stack<int> n;
    cin >> k;
    for (int i=0; i<k; i++)
    {
        int j;
        cin >> j;
        if(j == 0) n.pop();
        else n.push(j);
    }
    long long sum = 0;
    while(n.size())
    {
        sum += n.top();
        n.pop();
    }
    cout << sum;
}