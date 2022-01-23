#include<stdio.h>
#include<conio.h> 
#include<time.h>
#include<stdlib.h>


int main()
{   
    struct timespec start1,end1;
    clock_gettime(CLOCK_MONOTONIC, &start1);

    int n=128;
    

    double a[n][n];
    double b[n][n];
    double c[n][n];

    srand(time(0));

    for(int i=1;i<=n;i++)
    {
     for(int j=1;j<=n;j++)
     {
         a[j][j]=rand()%100*0.1;
         b[i][j]=rand()%100*0.1;
     }
    }
    
    struct timespec start,end;
    clock_gettime(CLOCK_MONOTONIC, &start);

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {

            c[i][j]=0;
            for(int k=1; k<=n; k++)
            {
                c[i][j]+=a[i][k]*b[k][j];
            }
        }
    }

    
    for(int i=1;i<=n;i++)
    {
     for(int j=1;j<=n;j++)
     {
         printf("%f ", c[i][j]);
     }
     printf("\n");
    }

    clock_gettime(CLOCK_MONOTONIC, &end);
    clock_gettime(CLOCK_MONOTONIC, &end1);
    
    double meat_time=end.tv_sec-start.tv_sec;
    meat_time+=(end.tv_nsec-start.tv_nsec)*0.000000001;
    printf("Meat time = %f seconds\n", meat_time);

    double time=end1.tv_sec-start1.tv_sec;
    time+=(end1.tv_nsec-start1.tv_nsec)*0.000000001;
    printf("Total time = %f seconds\n", time);
    return 0;
}