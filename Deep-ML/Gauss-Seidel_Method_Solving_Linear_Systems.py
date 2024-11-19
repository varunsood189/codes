import numpy as np

def gauss_seidel(A, b, n, x_ini=None):
	if x_ini is None:
		x = np.zeros_like(b)
	else:
		x = x_ini
	for _ in range(n):
		for i in range(len(x)):
			x[i] = 1/A[i][i]*(b[i]-sum([A[i][j]*x[j] for j in range(len(x)) if j<i])-sum([A[i][j]*x[j] for j in range(len(x)) if j>i]))
	return x
