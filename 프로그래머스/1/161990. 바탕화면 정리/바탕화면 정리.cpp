#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    int minw = 51;
    int maxw = 0;
    int minh = 51;
    int maxh = 0;
    // 바탕화면에 있는 파일을 받아서 
    // 드래그의 시작시점과 드래그의 끝점을 반환한다
    for(int i=0; i<wallpaper.size(); i++)
    {
        for(int j = 0; j<wallpaper[i].size(); j++)
        {
            if(wallpaper[i][j] == '#')
            {
                if(minw >= j) minw = j;
                if(maxw <= j) maxw = j+1;
                if(minh >= i) minh = i;
                if(maxh <= i) maxh = i+1;
            }
        }
    }
    answer.push_back(minh);
    answer.push_back(minw);
    answer.push_back(maxh);
    answer.push_back(maxw);
    return answer;
}