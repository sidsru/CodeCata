#include <iostream>
#include <algorithm>
using namespace std;
/*bool binarySearch(int arr[], int len, int target)
{
    int start = 0;
    int last = len-1;
    int mid;
    while(start<=last)
    {
        mid = (start + len) / 2;
        if(target == arr[mid]) return true;
        else if(arr[mid] < target) start = mid+1;
        else last = mid - 1;
    }
    return false;
}*/

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n;
    int* arr = new int[n];
    for (int i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr+n);
    cin >> m;
    for(int i=0; i<m; i++)
    {
        int b;
        cin >> b;
        if(binary_search(arr, arr+n, b)) cout << 1 << "\n";
        else cout << 0 << "\n";
    }
}