#include <iostream>

int main ()
{
    int a, b, c, n;
    std::cin >> a >> b;
    std::cin >> c;
    std::cin >> n;
    if(((a * n) + b <= c * n) && a <= c) std::cout << 1;
    else std::cout << 0;
}