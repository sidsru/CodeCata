#include <iostream>
#include <algorithm>
using namespace std;

bool comp(string a, string b)
{
    if(a.size() == b.size())
    {
        return a < b;
    }
    return a.size() < b.size();
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    string s[20001];
    for(int i=0; i<n; i++)
    {
        cin >> s[i];
        //if(find(dano.begin(), dano.end(), s) == dano.end());
    }
    sort(s, s+n, comp);
    string before = "";
    for(int i=0;i<n;i++)
    {
        if(before == s[i]) continue;
        cout << s[i] << "\n";
        before = s[i];
    }
    return 0;
}