#include <iostream>

using namespace std;
int arr [300];
int DP[300];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    DP[0] = arr[0];
    DP[1] = arr[1] + arr[0];
    DP[2] = max(arr[0] + arr[2], arr[1] + arr[2]);
    for(int i=3; i<n; i++)
    {
        DP[i] = max(DP[i-2] + arr[i], DP[i-3] + arr[i-1] + arr[i]);
    }
    cout << DP[n-1];
}