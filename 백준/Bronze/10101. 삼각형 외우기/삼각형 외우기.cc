#include <set>
#include <iostream>

int main()
{
    int sum = 0;
    int n;
    std::set<int> angle;
    for(int i=0; i<3; i++)
    {
        std::cin >> n;
        sum += n;
        angle.insert(n);
    }
    if(sum != 180) 
    {
        std::cout << "Error" << std::endl;
        return 0;
    }
    switch(angle.size())
    {
        case 1:
            std::cout << "Equilateral" << std::endl;
            break;
        case 2:
            std::cout << "Isosceles" << std::endl;
            break;
        case 3:
            std::cout << "Scalene" << std::endl;
            break;
    }
    return 0;
}