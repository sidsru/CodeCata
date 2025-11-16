#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int pibo[41][2] = {0,};
    
    pibo[0][0] = 1;
    pibo[1][1] = 1;
    for(int i=2;i<41; i++)
    {
        pibo[i][0] = pibo[i-1][0] + pibo[i-2][0];
        pibo[i][1] = pibo[i-1][1] + pibo[i-2][1];
    }
    int t, num;
    cin >> t;
    for(int i=0; i<t; i++)
    {
        cin >> num;
        cout << pibo[num][0] << " " <<pibo[num][1] << '\n';
    }
}