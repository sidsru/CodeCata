#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win) {
    vector<int> answer;
    int max = 0;
    int low = 0;
    int arr[7] = {6 ,6, 5, 4, 3, 2, 1};
    // 로또 알아볼수있는 부분만 맞췄다면 최저등수
    // 로또의 알아볼수 없는 부분도 모두 맞췄다면 최고 등수
    
    // 민우의 로또 번호 순회
    for ( auto a : lottos)
    {
        //해당 번호가 있는지 확인
        if (a == 0) 
        {
            ++max;
        }
        else if (find(win.begin(), win.end(), a) != win.end())
        {
            ++low;
            ++max;
        }
    }
    answer.push_back(arr[max]);
    answer.push_back(arr[low]);
    return answer;
}