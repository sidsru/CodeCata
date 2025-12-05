#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string temps = "", s;
    bool chack = false;
    int minnum = 0;
    cin >> s;
    for(int i=0; i<=s.size(); ++i)
    {
        if(s[i] == '+'|| s[i] == '-' || s[i] == '\0')
        {
            if(chack)
            {
                minnum -= stoi(temps);
            }
            else
            {
                minnum += stoi(temps);
            }
            temps = "";
        }
        else
            temps += s[i];
        if(s[i] == '-')
            chack = true;
    }
    cout << minnum;
}