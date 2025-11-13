#include <iostream>
#include <set>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    set<int> sets;
    for(int i=0; i<n; i++)
    {
        string s;
        int a;
        cin >> s;
        if(s == "add")
        {
            cin >> a;
            sets.insert(a);
        }
            
        else if(s == "remove")
        {
            cin >> a;
            sets.erase(a);
        }
            
        else if(s == "check")
        {
            cin >> a;
            if(sets.find(a) != sets.end())
                cout << 1 << "\n";
            else
                cout << 0 << "\n";
        }
        else if(s == "toggle")
        {
            cin >> a;
            if(sets.find(a) == sets.end())
                sets.insert(a);
            else
                sets.erase(a);
        }
        else if(s == "all")
        {
            for(int j=1; j<=20; j++)
            {
                sets.insert(j);
            }
        }
        else if(s == "empty")
        {
            sets.clear();
        }
            
    }
    return 0;
}