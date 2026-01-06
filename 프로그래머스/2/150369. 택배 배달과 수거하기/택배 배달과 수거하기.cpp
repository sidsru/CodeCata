#include <string>
#include <vector>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
	int deliverable = 0;
	int pickable = 0;
    for (int i = n-1; i >= 0; --i)
    {
        int cnt = 0;
		deliverable += deliveries[i];
        pickable += pickups[i];
        while(deliverable >0 || pickable >0)
        {
            deliverable -= cap;
            pickable -= cap;
			++cnt;
        }
        answer += (i + 1) * 2 * cnt;
    }
    return answer;
}