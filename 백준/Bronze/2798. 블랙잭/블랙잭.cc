#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
std::vector<int> Division(std::string& s)
{
    std::istringstream Ss(s);
    std::string temp;
    std::vector<int> Nums;
    while(Ss >> temp)Nums.push_back(stoi(temp));
    return Nums;
}

int approximation(std::vector<int> s,int n, int m)
{
    int sum = 0, result = 0;  
    for(int i = 0; i < n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            for(int k = j+1; k<n; k++)
            {
                sum = s[i] + s[j] + s[k];
                if(sum >result && sum <= m) result = sum;
            }
        }
    }
    return result;
}
int main()
{
    
    
    int N, M;
    std::cin >> N >> M;
    getchar();
    
    std::string Rist;
    getline(std::cin, Rist);
    //std::cout << Rist << std::endl;
    
    std::vector<int> Nums = Division(Rist);
    /*for(auto& a : Nums)
    {
        std::cout << a << std::endl;
    }*/
    std::cout << approximation(Nums, N, M);

    return 0;
}