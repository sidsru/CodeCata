#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(string a, string b)
{
    if(a.size() == b.size())
    {
        for(int i=0; i<a.size(); i++)
        {
            if(a[i] != b[i])return a[i] < b[i];
        }
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
    string s;
    vector<string> dano;
    for(int i=0; i<n; i++)
    {
        cin >> s;
        if(find(dano.begin(), dano.end(), s) == dano.end()) dano.push_back(s);
    }
    sort(dano.begin(), dano.end(), comp);
    for(vector<string>::iterator it = dano.begin(); it != dano.end(); it++)
    {
        cout << *it << "\n";
    }
    return 0;
}