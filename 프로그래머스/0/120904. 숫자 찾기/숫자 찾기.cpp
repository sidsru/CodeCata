#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int num, int k) {
    int answer = -1; 
    string a = to_string(num);
    for(int i=0; i<a.size(); i++)
    {
        if(a[i]-'0' == k)
        {
            answer = i+1;
            break;
        }
    }
    return answer;
}