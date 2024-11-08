import numpy as np
matrix = np.array([
    [0, 2, -1, -4],
    [2, 0, -1, -11],
    [-2, 0, 0, 22]
])
def rref(matrix):
	A  = matrix.astype(np.float32)
	m,n = matrix.shape
	for i in range(m):
	    if A[i,i]==0:
	        nonzeroindex = np.nonzero(A[i:,i])[0]
	        if len(nonzeroindex)==0: continue
	    
	        A[i] += A[nonzeroindex[0] + i]

	    if A[i,i] !=1:
	        A[i,:]/=A[i,i]
	    for j in range(m):
	        if i!=j:
	            A[j]-=A[j,i]*A[i]
	    print(A)
	return A
rref_matrix = rref(matrix)
print(rref_matrix)
