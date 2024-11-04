import numpy as np
def solve_jacobi(A: np.ndarray, b: np.ndarray, n: int) -> list:
	x = np.zeros(len(b))
	x_hold = x.copy()
	d_a = np.diag(A)
	A= A-np.diag(d_a)
	for _ in range(n):
	    for i in range(len(b)):
	        x_hold[i] = 1/d_a[i]* (b[i] - sum(A[i]*x))
	    x= x_hold.copy()
	return np.round(x,4).tolist()
A = [[5, -2, 3], [-3, 9, 1], [2, -1, -7]]
b = [-1, 2, 3]
n=2

print(solve_jacobi(A,b,n)) 
	
