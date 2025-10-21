#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(vector<int> elements) {
    unordered_set<int> sums;
    
    for(int i=0; i<elements.size(); i++)
    {
        int sum = 0;
        for(int j=i; j< i + elements.size(); j++)
        {
            sum += elements[j % elements.size()];
            sums.insert(sum);
        }
    }
    return sums.size();
}