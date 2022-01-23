#include<stdio.h>
#include<conio.h> 

#include<time.h>

int a[101]={0};

long long fibonacci(int n)
{
    
    a[1]=1;
    a[2]=1;

    if(a[n]==0)
    {
    a[n]= fibonacci(n-1)+fibonacci(n-2);
    }
    return a[n];
}

int main(void)
{
    struct timespec start,end;
    clock_gettime(CLOCK_MONOTONIC, &start);
    for(int i=1; i<=100; i++)
    {
        printf("%llu\n",fibonacci(i));
    }

    clock_gettime(CLOCK_MONOTONIC, &end);
    double time=end.tv_sec-start.tv_sec;
    time+=(end.tv_nsec-start.tv_nsec)*0.000000001;
    printf("Total time = %f sec", time);
    return 0;
}
