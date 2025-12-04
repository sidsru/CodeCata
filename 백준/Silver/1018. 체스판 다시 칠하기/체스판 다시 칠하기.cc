#include <stdio.h>
#include <vector>
#include <string>
using namespace std;

string W[8] =
{
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW"
};
string B[8] = 
{
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB"
};
char arr[50][50];
inline int Min(const int& a, const int& b) {return a < b ? a : b;}

int compW(const int& x, const int& y)
{
    int result = 0;
    for(int i=0; i<8; ++i)
        for(int j=0; j<8; ++j)
            if(arr[x+i][y+j] != W[i][j])
                ++result;
    return result;
}
int compB(const int& x, const int& y)
{
    int result = 0;
    for(int i=0; i<8; ++i)
        for(int j=0; j<8; ++j)
            if(arr[x+i][y+j] != B[i][j])
                ++result;
    return result;
}
int main()
{
    int n, m;
    
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; ++i)
    {
        scanf("%s", arr[i]);
    }
        
    int minnum = 65, answer = 0;
    for(int i=0; i<n-7; ++i)
        for(int j=0; j<m-7; ++j)
        {
            minnum = Min(Min(compB(i,j),compW(i,j)), minnum);
        }
    printf("%d", minnum);
}