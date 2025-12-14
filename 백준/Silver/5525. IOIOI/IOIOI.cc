#include <iostream>
using namespace std;

int main()
{
    int n, length, cnt = 0, temp = 0;
    int counting = 0, tempcnt = 0;
    cin >> n >> length;
    string s;
    cin >> s;
    for(int i = 1; i < length-1; ++i)
    {
        char c = s[i-1];
        if(c != s[i])
        {
            if(s[i] == 'O')
            {
                if(s[i+1] == 'I')
                    ++counting;
            }
        }
        else
        {
            tempcnt = counting >= n ? counting - n + 1 : 0;
            cnt += tempcnt;
            tempcnt = 0;
            counting = 0;
        }
    }
    tempcnt = counting >= n ? counting - n + 1 : 0;
    cnt += tempcnt;
    cout << cnt;
}