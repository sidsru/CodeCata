#include <string>
#include <vector>

using namespace std;

int solution(int n, int k) {
    int nsum = n * 12000;
    int ksum = (k-(n/10)) * 2000;
    int answer = nsum + ksum;
    return answer;
}