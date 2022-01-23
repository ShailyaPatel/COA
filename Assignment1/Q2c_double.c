#include<stdio.h>
#include<conio.h> 
#include<time.h>
#include<stdlib.h>


int main()
{
    int n=32;
    

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
         printf("%d ", c[i][j]);
     }
     printf("\n");
    }

    clock_gettime(CLOCK_MONOTONIC, &end);
    double time=end.tv_sec-start.tv_sec;
    time+=(end.tv_nsec-start.tv_nsec)*0.000000001;
    printf("Total time = %f seconds", time);
    return 0;
}