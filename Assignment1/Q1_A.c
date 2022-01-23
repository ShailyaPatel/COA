#include<stdio.h>
#include<conio.h> 

#include<time.h>

long long fibonacci(int n)
{
    if(n==1 || n==2)
        return 1;
    return fibonacci(n-1)+fibonacci(n-2);
}


int main(void)
{

    struct timespec start,end;

    clock_gettime(CLOCK_MONOTONIC, &start);
    
    for(int i=1;i<=45;i++)
    {
        printf("%lld\n",fibonacci(i));
    }

    clock_gettime(CLOCK_MONOTONIC, &end);
    double time=end.tv_sec-start.tv_sec;
    time+=(end.tv_nsec-start.tv_nsec)*0.000000001;

    printf("Total time = %f sec", time);
    return 0;
}

