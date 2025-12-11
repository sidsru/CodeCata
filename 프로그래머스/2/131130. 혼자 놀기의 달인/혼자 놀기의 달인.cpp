#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> cards) {
    int answer = 1;
    vector<int> v;
    bool visible[101] = {false, };
    for(int i=0; i<cards.size(); ++i)
    {
        if(visible[i])
            continue;
        
        int NowCard = i;
        visible[NowCard] = true;
        int count = 1;
        while(true)
        {
            NowCard = cards[NowCard]-1;
            if(visible[NowCard])
                break;
      
            visible[NowCard] = true;
            ++count;
        }
        v.push_back(count);
    }
    if(v.size() < 2)
        return 0;
    sort(v.rbegin(), v.rend());
    return v[0] * v[1];
}