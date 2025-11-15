#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool comp(int a, int b)
{
    return a > b;
}
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    vector<int> p(N);
    for(int i=0; i<N; i++)
    {
        int t;
        cin >> t;
        p.push_back(t);
    }
    sort(p.begin(), p.end(), comp);
    int total = 0;
    for(int i=0; i<N; i++)
    {
        int sum = 0;
        for(int j=i; j<N; j++)
        {
            sum += p[j];
        }
        total += sum;
    }
    cout << total << '\n';
}