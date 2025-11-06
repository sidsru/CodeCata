#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <iostream>

using namespace std;
// 시:분을 -> 분 형태로 바꾸어 주는 함수
int GetMin(string time)
{
    return stoi(time.substr(0,2)) * 60 + stoi(time.substr(3,2));
}

struct ParkingInfo
{
    int TotalParking;
    int InParking;
    bool in;
};

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<int, ParkingInfo> Parking;
    for(int i=0; i<records.size();i++)
    {
        int min = GetMin(records[i].substr(0,5));
        bool Isin = records[i][11] == 'I'? true : false;
        int number = stoi(records[i].substr(6,4));
        
        if(Parking.find(number) == Parking.end())
        {
            Parking[number].TotalParking = -fees[0];
            Parking[number].InParking = min;
            Parking[number].in = Isin;
        }
        else
        {
            if(Isin)
            {
                Parking[number].InParking = min;
                Parking[number].in = true;
                
            }
            else
            {
                Parking[number].TotalParking += min - Parking[number].InParking;
                Parking[number].in = false;
            }
        }
    }
    for(pair<int, ParkingInfo> it : Parking)
    {
        int BaseCost = fees[1];
        if(it.second.in)
        {
            it.second.TotalParking += (GetMin("23:59") - it.second.InParking);
        }
        
        if(it.second.TotalParking > 0)
        {
            BaseCost += ceil(it.second.TotalParking /(float)fees[2]) * fees[3];
        }
        cout << BaseCost << " ";
        answer.push_back(BaseCost);
    }
    return answer;
}