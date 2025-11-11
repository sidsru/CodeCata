#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int N;
    cin >> N;
    for(int i=0; i<N; i++)
    {
        int m,n;
        cin >> m >> n;
        priority_queue<int> sorts;
        queue<pair<int, int>> key;
        for(int j=0; j<m; j++)
        {
            int a;
            cin >> a;
            sorts.push(a);
            key.push({a, j});
        }
        int count = 1;
        while(1)
        {
            //cout << key.front().first << " " << key.front().second << " " <<sorts.top() << "\n";
            if(key.front().first >= sorts.top())
            {
                if(key.front().second == n) 
                {
                    cout << count << "\n";
                    break;
                }
                sorts.pop();
                key.pop();
                ++count;
            }
            
            else
            {
                key.push({key.front().first, key.front().second});
                key.pop();
            }
        }
        //cout << "\n";
    }
    return 0;
}