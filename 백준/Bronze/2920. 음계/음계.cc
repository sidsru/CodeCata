#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool comp(vector<int> a, vector<int> b)
{
    for(int i=0; i<a.size(); i++)
    {
        if(a[i] != b[i]) return false;
    }
    return true;
}
    
string umgestring(vector<int> umges)
{
    vector<int> temp = umges;
    sort(temp.begin(), temp.end());
    if(comp(temp,umges)) return "ascending";
    sort(temp.rbegin(), temp.rend());
    if(comp(temp,umges)) return "descending";
    return "mixed ";
}

int main()
{
    vector<int> umge;
    int n;
    for(int i=0; i<8; i++)
    {
        cin >> n;
        umge.push_back(n);
    }
    cout << umgestring(umge);
}