#include <iostream>
#include <vector>
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
    string s;
    vector<string> dano;
    for(int i=0; i<n; i++)
    {
        cin >> s;
        //if(find(dano.begin(), dano.end(), s) == dano.end());
        dano.push_back(s);
    }
    sort(dano.begin(), dano.end(), comp);
    string before = "";
    for(vector<string>::iterator it = dano.begin(); it != dano.end(); it++)
    {
        if(before == *it) continue;
        cout << *it << "\n";
        before = *it;
    }
    return 0;
}