#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool check4(vector<int>& v){
    if(vector<int>(v.end()-4, v.end()) == vector<int>{1,2,3,1}){
        return true;
    }
    return false;
}

int solution(vector<int> ingredient) {
    int answer = 0;
    vector<int> v;
    for(int& it: ingredient){
        v.push_back(it);
        while(check4(v)){
            for(int i=0; i<4; i++) v.pop_back();
            answer++;
        }
    }
    return answer;
}