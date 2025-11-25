#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long arr[101] = {0,1, 1, 1, 2, 2, 3, 4, 5, 7, 9,};
    for(int i=11; i<=101;i++)
        arr[i] = arr[i-1] + arr[i-5];
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        cout << arr[n] << '\n';
    }
}