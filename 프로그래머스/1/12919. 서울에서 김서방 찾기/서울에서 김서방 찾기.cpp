#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
    string answer = "";
    int th;
    for(int i=0; i<seoul.size(); i++)
    {
        if(seoul[i] == "Kim")
        {
            th = i;
            break;
        }
    }
    answer = "김서방은 " + to_string(th) +"에 있다";
    return answer;
}