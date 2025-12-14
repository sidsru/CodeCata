#include <iostream>
using namespace std;

bool chack(const int& n, const int& point, const string& s)
{
    for(int i = 1; i<= n<<1; ++i)
    {
        if(i & 1)
        {
            if(s[i+point] != 'O')
            {
                return false;
            }
        }
        else
        {
            if(s[i+point] != 'I')
            {
                return false;
            }
        }
    }
    return true;
}
int main()
{
    int n, length, cnt = 0;
    cin >> n >> length;
    string s;
    cin >> s;
    for(int i=0; i<length - n; ++i)
    {
        if(s[i] == 'I')
            if(chack(n, i, s))
                ++cnt;
    }
    cout << cnt;
}