import random

import time

n=int(32)

def matrix(n,a): 
    
    for i in range(n):
        for j in range(n):     
            print (a[i][j],end = " ")    
        


def product(n,b,c):
 
    ans= [[0 for x in range(n)]for y in range (n)]
     
    for i in range(n):
        for j in range(n):
            ans[i][j] = 0
            for x in range(n):           
                ans[i][j]+= (b[i][x]*c[x][j])        
    matrix(n,ans)       
    print()
   
b= [[float(random.randint(0,100) + random.random()) for x in range(n)] for y in range (n)]

c= [[float(random.randint(0,100) + random.random()) for x in range(n)] for y in range (n)]

matrix(n,b)
print()
matrix(n,c)
print()

start_time=time.time()
product(n,b,c)
print("Time = ",time.time()-start_time, "sec")