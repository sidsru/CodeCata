#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> array) {
    int answer = 0;
    //순서대로 정렬(O(NlogN)의 시간복잡도)
    sort(array.begin(), array.end());
    
    //최빈값을 찾아줄 백터 선언
    vector<int> num;
    // 비교를 위해 최대값의 빈도수를 저장해줄 max 
    // 2번째로 자주나온 빈도수를 저장할 count
    // 최대값을 저장해줄 temp 변수 선언
    int max = 0, count = 0, temp = 0;
    //입력받은 백터의 사이즈만큼 실행
    for(int i=0; i<array.size(); i++)
    {
        //처음 시행시 진행
        if(i == 0)
        {
            //초기값 설정
            temp = array[i];
            ++count;
            num.push_back(array[i]);
        }
        //처음이 아닌땐 이쪽으로 진행
        else
        {
            //템프에 저장한값과 이전 값이 동일하다면 카운트 증가
            if(temp == array[i]) 
            {
                ++count;
            }
            //아니라면 템프에 현재값을 업데이트하고 카운트를 1로 초기화
            else
            {
                temp = array[i];
                count = 1;
            }
            //최대 카운트가 현재 카운트를 넘었다면
            if(max<count)
            {
                //백터 초기화후 갱신 후 현재 변수를 넣어주고 현재카운트를 맥스로 반영
                num.clear();
                num.push_back(array[i]);
                max = count;
            }
            //만약 같다면
            else if(max == count)
            {
                //변수 초기화하지 않고 현재 변수만 추가해줌
                num.push_back(array[i]);
            }
            //위 과정에서 나온 빈도수가 같다면 백터사이즈가 2인 상태로 유지되며 한번더 나온다면 초기화후 최빈값을 최신화해줄것임
        }
    }
    //사이즈가 1이면 최빈값이 결정됨
    if(num.size() == 1)
    {
        return num[0];
    }
    //아니라면 중복된 최빈값이 있기때문에 -1을 반환
    else
    {
        return -1;
    }
}