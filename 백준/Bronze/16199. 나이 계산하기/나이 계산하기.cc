#include <stdio.h>

int main()
{
    int birthDay[3];
    int Now[3];
    scanf("%d %d %d",&birthDay[0],&birthDay[1],&birthDay[2]);
    scanf("%d %d %d",&Now[0],&Now[1],&Now[2]);
    int age[3] = {0,};
    age[0] = Now[0] - birthDay[0];
    age[1] = Now[0] - birthDay[0] + 1;
    age[2] = Now[0] - birthDay[0];
    if(birthDay[1]>=Now[1])
    {
        if(birthDay[1]==Now[1])
        {
            if(birthDay[2]>Now[2])
                --age[0];
        }
        else
        {
            --age[0];
        }
    }
    for(int i=0; i<3; ++i)
        printf("%d\n",age[i]);
    
}