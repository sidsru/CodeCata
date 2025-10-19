#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> x, y;
    int a, b;
    for(int i = 0; i < 3; i++)
    {
        std::cin >> a >> b;
        if(find(x.begin(), x.end(), a) == x. end()) x.push_back(a);
        else x.erase(remove(x.begin(), x.end(), a), x.end());
        
        if(find(y.begin(), y.end(), b) == y. end()) y.push_back(b);
        else y.erase(remove(y.begin(), y.end(), b), y.end());
    }
    std::cout << x[0] << " " << y[0] << std::endl;
    
}