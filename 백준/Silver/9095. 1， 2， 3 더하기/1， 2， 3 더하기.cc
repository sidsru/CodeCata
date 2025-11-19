#include<iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int arr[11]={0, 1, 2, 4,};
    for(int i=4; i<11; i++)
    {
        arr[i] = arr[i-1] + arr[i-2] + arr[i-3];
    }
    int T;
    cin >> T;
    for(int i=0; i<T; i++)
    {
        int n;
        cin >> n;
        cout << arr[n] << '\n';
    }
}