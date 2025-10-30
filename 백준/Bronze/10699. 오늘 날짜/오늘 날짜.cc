#include <ctime>
#include <cstdio>

int main ()
{
    time_t timer;
    struct tm* t;
    timer = time(NULL);
    t = localtime(&timer);
    
    printf("%d-%d-%d", t->tm_year +1900, t->tm_mon + 1, t->tm_mday);
}