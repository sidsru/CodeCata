#include <iostream>
#include <queue>
using namespace std;

int main ()
{
    int a, b;
    cin >> a >> b;
    queue<int> que;
    for(int i=1; i<=a; i++)
    {
        que.push(i);
    }
    cout << "<";
    while(que.size() != 1)
    {
        for(int i=0; i<b-1; i++)
        {
            que.push(que.front());
            que.pop();
        }
        cout << que.front() << ", ";
        que.pop();
    }
    cout << que.front() << ">";
}