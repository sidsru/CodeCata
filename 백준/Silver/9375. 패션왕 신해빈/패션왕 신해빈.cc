#include <iostream>
#include <map>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin >> t;
    for(int i=0; i<t; i++)
    {
        int n, answer=1;
        cin >> n;
        map<string, int> m;
        for(int j=0; j<n; j++)
        {
            string name, s;
            cin >> name >> s;
            m[s]++;
        }
        for(map<string, int>::iterator it = m.begin(); it != m.end(); it++)
        {
            answer *= it->second+1;
        }
        cout << answer-1 << '\n';
    }
}