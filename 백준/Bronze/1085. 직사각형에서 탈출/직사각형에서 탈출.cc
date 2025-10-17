#include <iostream>
#include <cmath>
int main () 
{
    int x, y, w, h;
    std::cin >> x >> y >> w >> h;
    int a = std::min(x, w - x);
    int b = std::min(y, h - y);
    std::cout << std::min(a, b) << std::endl;
    return 0;
}