#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    int mun[12]{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30};
    int sum = 0;
    for(int i=0; i< a; i++)
    {
        sum += mun[i];
    }
    sum += b;
    int th = sum % 7;
    string s[7] {"THU", "FRI", "SAT", "SUN", "MON", "TUE", "WED" };
    return answer = s[th];
}