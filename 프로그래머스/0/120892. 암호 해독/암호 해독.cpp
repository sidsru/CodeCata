#include <string>
#include <vector>

using namespace std;

string solution(string cipher, int code) {
    string answer = "";
    int count = 0;
    for(int i=1; i<=cipher.size()/code; i++)
    {
        answer += cipher[i*code -1];
    }
    return answer;
}