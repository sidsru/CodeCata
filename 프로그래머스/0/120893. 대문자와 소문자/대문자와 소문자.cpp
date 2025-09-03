#include <string>
#include <vector>

using namespace std;

string solution(string my) {
    string answer = "";
    for(int i=0; i<my.size(); i++)
    {
        if(my[i] >= 'a' && my[i] <= 'z')
        {
            my[i] -= 'a';
            my[i] += 'A';
        }
        else
        {
            my[i] -= 'A';
            my[i] += 'a';
        }
    }
    return my;
}