#include <stdio.h>
#include <queue>
using namespace std;

inline int Max(const int& a, const int& b) { return a > b ? a : b; }
int main()
{
    int n, arr[10] = {0,}, types = 0, answer = 0;
    scanf("%d", &n);
    queue<int> q;
    for(int i=0; i<n; ++i)
    {
        int temp;
        scanf("%d", &temp);
        q.push(temp);
        
        if(arr[temp] == 0)
            ++types;
        ++arr[temp];
        while(types>2)
        {
            //printf("%d", answer);
            int top = q.front();
            q.pop();
            --arr[top];
            if(arr[top] == 0)
                --types;
        }
        answer = Max(answer, q.size());
    }
    printf("%d", answer);
    return 0;
}