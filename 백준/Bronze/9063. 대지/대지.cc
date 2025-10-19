#include <iostream>
#include <algorithm>

int main()
{
    int n, x, y;
    int minx = 10001, miny = 10001;
    int maxx = -10001, maxy = -10001;
    std::cin >> n;
    for(int i=0; i<n; i++)
    {
        std::cin >> x >> y;
        minx = std::min(x, minx);
        miny = std::min(y, miny);
        maxx = std::max(x, maxx);
        maxy = std::max(y, maxy);
    }
    std::cout << (maxx - minx) * (maxy - miny) << std::endl;
}