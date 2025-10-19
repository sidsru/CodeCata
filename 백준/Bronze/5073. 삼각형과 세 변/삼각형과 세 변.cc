#include <iostream>
#include <set>
#include <algorithm>

int main()
{
    int a, b, c;
    while(1)
    {
        std::set<int> n;
        std::cin >> a >> b >> c;
        if(a == 0 && b == 0 && c == 0) break;
        n.insert(a);
        n.insert(b);
        n.insert(c);
        int max = std::max(std::max(a, b), c);
        if(max >= (a + b + c - max)) 
        {
            std::cout << "Invalid" << std::endl;
            continue;
        }
        switch(n.size())
        {
            case 1:
                std::cout << "Equilateral" << std::endl;
                break;
            case 2:
                std::cout << "Isosceles " << std::endl;
                break;
            case 3:
                std::cout << "Scalene" << std::endl;
                break;
        }
    }
}