/*MenOfPassion(A[], n) {
    sum <- 0;
    for i <- 1 to n - 2
        for j <- i + 1 to n - 1
            for k <- j + 1 to n
                sum <- sum + A[i] × A[j] × A[k]; # 코드1
    return sum;
}*/
#include <iostream>

int main () 
{
    long  n;
    std::cin >> n;
    std::cout << (n * (n-1)*(n-2)) /6 << std::endl << 3;
}