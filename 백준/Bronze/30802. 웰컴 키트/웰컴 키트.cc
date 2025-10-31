#include <iostream>
using namespace std;

int main ()
{
    int n,arr[6]; // 4b + 24b, 28b
    cin >> n; // 0.00000001초
    for(int i=0; i<6; i++) // 4b ,32b 0.00000013초
    {
        cin >> arr[i];
    }
    int t, p, answer = 0; // 4b + 4b + 4b, 44b
    cin >> t >> p;
    for(int i=0; i<6; i++) // 4b, 48b
    {
        //cout <<arr[i]/t+1<< "\n";
        answer += arr[i]/t+1;
        if(arr[i]%t == 0) --answer;
    }
    cout << answer << "\n" << n/p << " " << n%p;
}