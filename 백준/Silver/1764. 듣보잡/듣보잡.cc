#include <iostream>
#include <map>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, count = 0;
    cin >> n >> m;
    map<string, int> man;
    for(int i=0; i < n+m; i++)
    {
        string s;
        cin >> s;
        ++man[s];
        if(man[s]>=2)
            ++count;
    }
    cout << count << "\n";
    for(map<string,int>::iterator it = man.begin(); it != man.end();it++)
    {
        if(it->second == 2)
            cout << it->first << "\n";
    }
}