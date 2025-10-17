#include <iostream>
#include <cmath>
bool Prime(int n)
{
    if(n == 1) return false;
    for(int i = 2; i <= sqrt(n); i++)
    {
        if(n % i == 0) return false;
    }
    return true;
}
int main()
{
    int n;
    std::cin >> n;
    int i = 2;
    while(n != 1)
    {
        if( n % i == 0 && Prime(i)) 
        {
            std::cout << i << std::endl;
            n /= i;
        }
        else
        {
            ++i;
            continue;
        }
        
    }
    return 0;
}