#include <iostream>
#include <cctype>
using namespace std;

int main()
{
    string s;
    cin >> s;
    for(int i=0; i<s.size(); i++)
    {
        if('a'<=s[i] && s[i]<='z') s[i] = toupper(s[i]);
        else s[i] = tolower(s[i]);
    }
    cout << s;
    return 0;
}