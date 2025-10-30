#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*bool bSearch(int* arr, int arr2, int a)
{
    int start = 0;
    int end = arr2;
    int m;
    while(end - start >= 0)
    {
        m = (start + end) / 2;
        if(arr[m] == a) return true;
        else if(arr[m] > a) end = m - 1;
        else if(arr[m] < a) start = m + 1;
    }
    return false;
}*/

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m, num;
    cin >> n;
    int* arr = new int[n];
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    cin >> m;
    for(int i=0; i<m; i++)
    {
        cin >> num;
        if( binary_search(arr, arr + n, num)) cout << 1 << " ";
        else cout << 0 << " ";
    }
    return 0;
}