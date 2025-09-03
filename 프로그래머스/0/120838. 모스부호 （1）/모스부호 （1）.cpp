#include <string>
#include <vector>
#include <map>
using namespace std;
map<string, char> morse =
{ 
    {".-",'a'},
    {"-...",'b'},
    {"-.-.",'c'},
    {"-..",'d'},
    {".",'e'},
    {"..-.",'f'},
    {"--.",'g'},
    {"....",'h'},
    {"..",'i'},
    {".---",'j'},
    {"-.-",'k'},
    {".-..",'l'},
    {"--",'m'},
    {"-.",'n'},
    {"---",'o'},
    {".--.",'p'},
    {"--.-",'q'},
    {".-.",'r'},
    {"...",'s'},
    {"-",'t'},
    {"..-",'u'},
    {"...-",'v'},
    {".--",'w'},
    {"-..-",'x'},
    {"-.--",'y'},
    {"--..",'z'}
};
string solution(string letter) {
    string answer = "";
    string temp = "";
    for(int i=0; i <letter.size(); i++)
    {
        if(letter[i] != ' ')
        {
            temp += letter[i];
        }
        else
        {
            auto it = morse.find(temp);
            answer += it->second;
            temp = "";
        }
        if(i == letter.size()-1)
        {
            auto it = morse.find(temp);
            answer += it->second;
            temp = "";
        }
    }
    return answer;
}