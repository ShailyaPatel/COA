#include<stdio.h>
#include<conio.h> 

#include<time.h>

int main(void)
{
    struct timespec start,end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    printf("1\n");
    
    for(int i=2;i<=100;i++)
    {
        unsigned long long a=0;
        unsigned long long b=1;
        unsigned long long c=1;

        int j=2;
        while(j<=i)
        {
            c=a+b;

            a=b;
            b=c;
            j++;
        }
        
        printf("%llu\n",c);
    }
    clock_gettime(CLOCK_MONOTONIC, &end);
    double time=end.tv_sec-start.tv_sec;
    time+=(end.tv_nsec-start.tv_nsec)*0.000000001;

    printf("Total Time= %f sec", time);
    return 0;
}