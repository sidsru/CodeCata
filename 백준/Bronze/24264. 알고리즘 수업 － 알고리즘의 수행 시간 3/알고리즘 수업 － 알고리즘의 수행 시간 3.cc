/*MenOfPassion(A[], n) {
    sum <- 0;
    for i <- 1 to n
        for j <- 1 to n
            sum <- sum + A[i] × A[j]; # 코드1
    return sum;
}*/
#include <iostream>

int main ()
{
    long n;
    std::cin >> n;
    std::cout << n * n << std::endl << 2;
}