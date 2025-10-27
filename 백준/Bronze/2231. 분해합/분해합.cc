#include <iostream>

int main ()
{
    int N;
    std::cin >> N;
    int sum, i;
    for(i=1; i<N; i++)
    {
        int temp = i;
        sum = i;
        while (temp)
        {
            sum += temp%10;
            temp /= 10;
            
        }
        if(sum == N) break;
    }
    if(sum == N) std::cout << i << std::endl;
    else std::cout << 0 << std::endl;
    return 0;
}