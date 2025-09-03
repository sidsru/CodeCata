#include <string>
#include <vector>

using namespace std;

string solution(string my) {
    string answer = "";
    for(int i=0; i<my.size(); i++)
    {
        for(int j = i+1;j<my.size(); j++)
        {
            if(my[i] == my[j])
            {
                my.erase(my.begin() + j);
                --j;
            }
        }
    }
    return answer = my;
}