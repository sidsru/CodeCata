#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    string temp = "";
    string rest = "";
    string arr[10]{"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    string in[10]{"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
    for(auto c : s)
    {
        if(isdigit(c))
        {
            rest += c;
        }
        else
        {
            temp += c;
            for(int i=0; i<10; i++)
            {
                if(arr[i] == temp)
                {
                    rest += in[i];
                    temp = "";
                }
            }
        }
    }
    answer = stoi(rest);
    return answer;
}