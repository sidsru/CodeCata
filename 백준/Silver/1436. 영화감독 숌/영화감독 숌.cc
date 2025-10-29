#include <iostream>
using namespace std;

int findSiries(int n)
{
    int count = 0, i = 666;
    string target;
    while(1)
    {
        target = to_string(i);
        for(int j=0; j<target.size()-2; j++)
        {
            if(target[j] == '6' && target[j+1] == '6' && target[j+2] == '6')
            {
                ++count;
                if(n == count) return i;
                break;
            }
        }
        ++i;
    }
}

int main ()
{
    int N;
    cin >> N;
     cout << findSiries(N) << endl;
}