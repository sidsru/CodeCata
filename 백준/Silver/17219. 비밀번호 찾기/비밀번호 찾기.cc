#include <iostream>
#include <map>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, m;
    map<string, string> password;
    cin >> n >> m;
    for(int i=0; i<n; i++)
    {
        string address, pass;
        cin >> address >> pass;
        password[address] = {pass};
    }
    for(int i=0; i<m; i++)
    {
        string s;
        cin >> s;
        cout << password[s] << '\n';
    }
    return 0;
}