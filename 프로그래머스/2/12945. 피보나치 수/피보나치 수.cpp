#include <string>
#include <vector>

using namespace std;

int Fivo(int n)
{
    vector<int> fivo{0,1};
    for(int i=1; i < n; i++)
    {
        fivo.push_back((fivo[i-1] + fivo[i])%1234567);
    }
    return fivo.back();
}

int solution(int n) {
    int answer = 0;
    int temp = Fivo(n);
    return answer = temp;
}