#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, int> um;
    for(vector<string> clothe : clothes)
        ++um[clothe[1]];
    
    for(unordered_map<string, int>::iterator it = um.begin(); it != um.end(); ++it)
        answer *= it->second + 1; 
    
    return answer - 1;
}