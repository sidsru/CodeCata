//#define_CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    int answer=0;
    scanf("%d", &n);
    vector<int> score;
    if(n != 0)
    {
        int temp = n;
        while(temp--)
        {
            int i;
            scanf("%d", &i);
            score.push_back(i);
        }
        sort(score.begin(), score.end());
        int c = round(n * 0.15f);
        //printf("%d", c);
        double sum = 0;
        for(int i=c; i<score.size() - c; i++)
        {
            sum += score[i];
        }
        //printf("%d\n",sum);
        n -= (c*2);
        answer = round(sum/n);
    }
    printf("%d", answer);
}