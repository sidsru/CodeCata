#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin >> n >> m;
    map<string, string> pokemonNumber;
    map<string, string> pokemonName;
    for(int i=1; i<=n; i++)
    {
        string s;
        cin >> s;
        pokemonNumber[to_string(i)] = {s};
        pokemonName[s] = {to_string(i)};
    }
    for(int i=0; i<m; i++)
    {
        string s;
        cin >> s;
        if(pokemonNumber.find(s) != pokemonNumber.end())
            cout << pokemonNumber[s] << '\n';
        if(pokemonName.find(s) != pokemonName.end())
            cout << pokemonName[s] << '\n';
    }
    return 0;
}