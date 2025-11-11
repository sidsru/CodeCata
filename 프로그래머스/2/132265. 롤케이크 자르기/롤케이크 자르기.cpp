#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    map<int, int> toping;
    map<int, int> comp;
    for(int& a : topping)
    {
        ++toping[a];
    }
    for(int i=0; i<topping.size(); i++)
    {
        if(toping.find(topping[i]) != toping.end())
        {
            --toping[topping[i]];
            if(toping[topping[i]] == 0)
                toping.erase(topping[i]);
            ++comp[topping[i]];
        }
        if(toping.size() == comp.size())
            ++answer;
                
    }
    /*for(map<int,int>::iterator it = toping.begin(); it !=toping.end(); it++)
    {
        cout << it->first << " " << it->second << "\n";
    }*/
    return answer;
}