#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> arr) {
    sort(arr.begin(), arr.end());
    int m = arr[arr.size()/2];
    int answer = m;
    return answer;
}