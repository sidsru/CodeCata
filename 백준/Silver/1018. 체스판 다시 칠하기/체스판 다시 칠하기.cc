#include <iostream>
#include <vector>
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
int compB(const vector<string>& s, const int& x, const int& y)
{
    int cnt = 0;
    for(int i=0; i<8; i++)
    {
        for(int j = 0; j<8; j++)
        {
            if(s[x+i][y+j] != B[i][j]) ++cnt;
        }
    }
    return cnt;
}
int compW(const vector<string>& s, const int& x, const int& y)
{
    int cnt = 0;
    for(int i=0; i<8; i++)
    {
        for(int j = 0; j<8; j++)
        {
            if(s[x+i][y+j] != W[i][j]) ++cnt;
        }
    }
    return cnt;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<string> s;
    for(int i = 0; i<n; i++)
    {
        string temp;
        cin >> temp;
        s.push_back(temp);
    }
    int Min = 65, answer = 0;
    for(int i=0; i<n-7;i++)
    {
        for(int j=0; j<m-7;j++)
        {
            answer = min(compB(s,i,j),compW(s,i,j));
            Min = min(answer, Min);
        }
    }
    cout << Min << endl;
}
