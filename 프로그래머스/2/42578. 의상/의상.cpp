#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, int> clothesmap;
    for(int i=0; i<clothes.size(); i++)
    {
        ++clothesmap[clothes[i][1]];
    }
    for(unordered_map<string, int>::iterator it = clothesmap.begin(); it != clothesmap.end(); it++)
    {
        //cout << it->first << " " << it->second << endl;
        answer *= it->second + 1;
    }
    
    return answer - 1;
}