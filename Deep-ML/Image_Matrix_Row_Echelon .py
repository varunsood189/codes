import numpy as np
def partial_pivoting(A,i,j):
    max_index = np.argmax(A[i:,i:],axis=0)[0]
    if max_index+i !=i:
        A[[max_index+i,i]]=A[[i,max_index+i]]	
    return A

def matrix_image(A):
	# Write your code here
    A_temp=A.copy()
    A= A.astype(float)
    n,m =A.shape
    for i in range(n):
        partial_pivoting(A,i,i)
        for j in range(i+1,n):
            A[j]-=A[i]*A[j][i]/A[i][i]
    X=[]
    for i in range(n):
        if A[i][i]>0:			
            X.append(A_temp[:,i])
    return np.array(X).T
    
