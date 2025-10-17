#include <iostream>
#include <cmath>
bool Prime(int n)
{
    if (n <= 1) return false;
    for(int i = 2; i <= n/2; i++)
    {
        if(n % i == 0) return false;
    }
    return true;
}
int main()
{
    int sum = 0, min = 0;
    int m,n;
    std::cin >> m >> n;
    for(int i=m; i<= n; i++)
    {
        if (Prime(i)) 
        {
            sum += i;
            if(min == 0) min = i;
        }
    }
    if(sum == 0) 
    {
        sum = -1;
        std::cout << sum << std::endl;
    }
    else
    {
        std::cout << sum << std::endl << min;
    }
    return 0;
}