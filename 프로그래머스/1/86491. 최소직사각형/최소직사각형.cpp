#include <string>
#include <vector>
using namespace std;

inline int Max(const int& a, const int& b){return  a > b ? a : b;}

int solution(vector<vector<int>> sizes) {
    int h = 0;
    int w = 0;
    for(vector<int> v : sizes)
    {
        if(v[0] > v[1])
        {
            h = Max(h, v[0]);
            w = Max(w, v[1]);
        }
        else
        {
            h = Max(h, v[1]);
            w = Max(w, v[0]);
        }
    }
    return h * w;
}