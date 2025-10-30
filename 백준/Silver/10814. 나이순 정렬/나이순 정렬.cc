#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool comp(pair<int,string> a,pair<int,string> b)
{
    return a.first < b.first;
}
int main()
{
    int n, age;
    string name;
    vector<pair<int,string>> person;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> age >> name;
        person.push_back({age, name});
    }
    stable_sort(person.begin(), person.end(), comp);
    for( vector<pair<int,string>>::iterator it = person.begin(); it != person.end(); it++)
    {
        cout << it->first << " " << it->second << "\n";
    }
}