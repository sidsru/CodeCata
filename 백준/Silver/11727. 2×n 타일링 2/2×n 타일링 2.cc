#include <iostream>
using namespace std;

int main()
{
    int arr[1000] = {1, 3};
    int n;
    cin >> n;
    for(int i=2; i<n; i++)
    {
        arr[i] = (arr[i-1] + (arr[i-2]*2)) % 10007;
    }
    cout << arr[n-1];
}