#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
int main()
{
    int n, Num;
    set<int> SortNum;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> Num;
        SortNum.insert(Num);
    }
    for(auto& answer : SortNum)
    {
        cout << answer << endl;
    }
}