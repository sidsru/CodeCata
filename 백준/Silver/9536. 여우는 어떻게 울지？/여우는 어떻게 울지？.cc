#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
int main()
{
    int N;
    std::cin >> N;
    std::cin.clear();
    std::string Buffer;
    getline(std::cin, Buffer);
    for(int i=0; i < N; i++)
    {
        std::string S, T;
        std::vector<std::string> A;
        getline(std::cin, S);
        std::stringstream Ss1(S);
        while(Ss1 >> T)
        {
            A.push_back(T);
        }
        
        /*for(auto& a : A)
        {
            std::cout << a << " ";
        }*/
        
        std::string G, Key, Temp, Value;
        std::map<std::string, std::string> Goes;
        
        while(1)
        {
            getline(std::cin, G);
            //std::cout << G << std::endl;
            if(G == "what does the fox say?") break;
            
            std::stringstream Ss2(G); 
            Ss2 >> Key >> Temp >> Value;
            Goes[Key] = Value;
            
        }
        
        for(auto& Iter : Goes)
        {
            A.erase(remove(A.begin(), A.end(), Iter.second), A.end());
            //std::cout << Iter.first << " " << Iter.second<<std::endl;
            //S.erase(S.find(S.begin(), S.end(), Iter.second));
        }
        //std::cout << S << std::endl;
        for(int i = 0; i < A.size()-1; i++)
        {
            std::cout << A[i] << " ";
        }
        std::cout << A.back() << std::endl;
    }
    
    return 0;
}