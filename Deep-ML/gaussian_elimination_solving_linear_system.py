import numpy as np

def partial_pivoting(A,i,j):
    max_index = np.argmax(A[i:,i:],axis=0)[0]
    if max_index+i !=i:
        A[[max_index+i,i]]=A[[i,max_index+i]]
    return A
    
def gaussian_elimination(A, b):
    """
    Solves the system Ax = b using Gaussian Elimination with partial pivoting.
    
    :param A: Coefficient matrix
    :param b: Right-hand side vector
    :return: Solution vector x
    """
    n,m =A.shape
    A_aug=np.hstack((A,b.reshape(-1,1)))
    for i in range(n):
        partial_pivoting(A_aug,i,i)
        for j in range(i+1,n):
            A_aug[j]-=A_aug[i]*A_aug[j][i]/A_aug[i][i]
    x=np.zeros(len(b))
    for i in range(n-1,-1,-1):
        x[i] = (A_aug[i,-1]-A_aug[i,i+1:m].dot(x[i+1:]))/A_aug[i][i]
    return x
