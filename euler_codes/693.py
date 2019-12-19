# -*- coding: utf-8 -*-
"""
Created on Mon Dec 16 20:56:23 2019

@author: varun
"""
"""
    ax=y is the first term,
    az+1=a2zmodz for z=x,x+1,x+2,… and
    the generation stops when a term becomes 0 or 1.

"""
import sys 
sys.setrecursionlimit(30000000)
def loop(az,z,count,arr):
    temp=(az*az)%z;
    #print("az = ",az,"z = ",z,"temp = ",temp,"count = ",count)
    if str(z)+","+str(temp) not in arr:  
        if((temp==1) or (temp==0)):
            arr[str(z)+","+str(temp)]=1
        else:
            arr[str(z)+","+str(temp)]=loop(temp,z+1,count+1,arr)
        return arr[str(z)+","+str(temp)]+1
    else:
        return arr[str(z)+","+str(temp)]

n=3000000 # set n = needed value
arr={}
count=1;    
max_value=0
for x in range(1,n+1): 
    if(x%10000==0):
        print(x)
    for y in range(1,x):            
        arr[str(x)+","+str(y)]=loop(y,x,count+1,arr)
        # arr[x][y]=loop(y,x,count+1,arr)
        # if(max_value<arr[x][y]):
        #     max_value=arr[x][y]    
        if(max_value<arr[str(x)+","+str(y)]):
            max_value=arr[str(x)+","+str(y)]    
    for y in range(1,x):
        del arr[str(x)+","+str(y)]
print(max_value)        
