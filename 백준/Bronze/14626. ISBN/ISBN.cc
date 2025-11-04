#include <iostream>
using namespace std;

int main()
{
    int sum = 0;
    string s;
    cin >> s;
    bool chack = false;
    for(int i=0; i<s.size(); i++)
    {
        bool IsEven = i%2;
        if(s[i] == '*') 
        {
            chack = IsEven;
        }
        else
        {
            sum += (s[i] - 48) * (IsEven ? 3 : 1);
        }
    }
    sum %= 10;
    
    if(chack) 
    {
        for(int i=0; i<10; i++)
        {
            if((sum+i*3)%10 == 0)
            {
                cout << i;
                break;
            }
        }
    }
    else cout << 10 - sum;
    return 0;
}