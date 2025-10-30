#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct 
{
    int x;
    int y;
}coordinate;

bool comp(coordinate a, coordinate b)
{
    if(a.y == b.y) return a.x < b.x;
    return a.y < b.y;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, X, Y;
    cin >> n;
    vector<coordinate> dot;
    for(int i=0; i<n; i++)
    {
        cin >> X >> Y;
        coordinate temp;
        temp.x = X, temp.y = Y;
        dot.push_back(temp);
    }
    sort(dot.begin(), dot.end(), comp);
    for(coordinate& a : dot)
    {
        cout << a.x << " " << a.y << "\n";
    }
    return 0;
}