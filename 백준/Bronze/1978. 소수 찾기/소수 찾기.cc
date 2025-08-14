#include <iostream>
using namespace std;

int main()
{
    int n, a;
    int cnt, res=0;
    cin >> n;//몇개를 입력할지
    for(int i = 0; i<n; i++)
    {
        cin >> a;// 각각 입력
        for (int o = 1; o <= a; o++)//1 a
        {
            if(a%o == 0) ++cnt;
        }
        if (cnt == 2) ++res;
        
        cnt = 0;
    }
    cout << res;
    return 0;
}