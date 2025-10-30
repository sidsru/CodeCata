#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(char a, char b)
{
    return a > b;
}
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
    string c;
    cin >> c;
    sort(c.begin(), c.end(), comp);
    cout << c << "\n";
}