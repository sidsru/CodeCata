#include <iostream>
using namespace std;

int pactorial(int n)
{
    int answer = 0;
    int five = 5;
    while(n>=five)
    {
        answer += n/five;
        five *= 5;
    }
    return answer;
}
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;

    cout << pactorial(n) <<"\n";
    return 0;
}