#include <string>
#include <vector>

using namespace std;

int solution(vector<int> box, int n) {
    int answer = 0;
    int a = box[0] * box[1];
    int b = n*n;
    int c = a / b;
    int d = box[2]/n;
    return answer = c * d;
}