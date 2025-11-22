#include <iostream>
#include <map>
#include <string>
#include <cctype>
using namespace std;
string Name[100001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    map<string, int> pokemon;
    int n,m;
    cin >> n >> m;
    for(int i=1; i<=n; i++)
    {
        cin >> Name[i];
        pokemon.insert(make_pair(Name[i], i));
    }
    for(int i=0; i<m; i++)
    {
        string s;
        cin >> s;
        if(isdigit(s[0]))
            cout << Name[stoi(s)] << '\n';
        if(!isdigit(s[0]))
        {
            map<string, int>::iterator it = pokemon.find(s);
            cout << it->second << '\n';
        }
        
    }
    return 0;
}