#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    for(int j=0; j<t; j++)
    {
        int k,n;
        cin >> k >> n;
        vector<int> v;
        for(int i=0; i<=n; i++)
        {
            v.push_back(i);
        }
        for(int i=1; i<=k; i++)
        {
            for(int j=1; j<=n; j++)
            {
                v[j] = v[j] + v[j-1];
            }
        }
        cout << v.back() << "\n";
    }
}