#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<vector<int>> line) {
	vector<pair<long long, long long>> points;
    long long minX = 10000000001;
    long long minY = 10000000001;
    long long maxX = -10000000001;
    long long maxY = -10000000001;
    for (int i = 0; i < line.size(); ++i)
    {
        for (int j = 0; j < line.size(); ++j)
        {
            if (j == i)
            {
                continue;
            }
#pragma region 교점 구하기
            long long A = line[i][0], B = line[i][1], E = line[i][2];
            long long C = line[j][0], D = line[j][1], F = line[j][2];
            long long denominator = (A* D) - (B*C);
            if (denominator == 0)
            {
                continue;
			}
            long long x = (B * F) - (E *D);
            long long y = (E * C) - (A * F);
            if (x % denominator != 0 || y % denominator != 0)
            {
                continue;
            }
            long long X = x / denominator;
            long long Y = y / denominator;
            points.push_back({ X, Y });

#pragma endregion

#pragma region 교점 구하기

            if (minX > X)
            {
                minX = X;
            }
            if (maxX < X)
            {
                maxX = X;
			}
            if (minY > Y)
            {
                minY = Y;
            }
            if (maxY < Y)
            {
                maxY = Y;
            }
#pragma endregion
        }
    }
    long long width = maxX - minX + 1;
    long long height = maxY - minY + 1;

	vector<string> answer(height, string(width, '.'));
    for (int i = 0; i < points.size(); ++i)
    {
        long long X = points[i].first - minX;
        long long Y = maxY - points[i].second;
        answer[Y][X] = '*';
	}
    return answer;
}