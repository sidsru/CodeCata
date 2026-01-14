// 프로그레머스
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string, int> sum; // 각 장르의 총합
    unordered_map<string, unordered_map<int, int>> musics; // 각 음악의 장르와 재생횟수, 인덱스를 묶은 객체
    for (int i = 0; i < genres.size(); ++i)
    {
        sum[genres[i]] += plays[i];
        musics[genres[i]][i] = plays[i];
    }
    while (!sum.empty())
    {
        string genre = "";
        int max = 0;

        for (unordered_map<string, int>::iterator it = sum.begin(); it != sum.end(); ++it)
        {
            if (max < it->second)
            {
                max = it->second;
                genre = it->first;
            }
        }
        for (int i = 0; i < 2; ++i)
        {
            int value = 0, idx = -1;
            for (pair<int, int> music : musics[genre])
            {
                if (value < music.second)
                {
                    value = music.second;
                    idx = music.first;
                }
            }
            if (idx == -1)
            {
                break;
            }
            answer.push_back(idx);
            musics[genre].erase(idx);
        }
        sum.erase(genre);
    }
    return answer;
}