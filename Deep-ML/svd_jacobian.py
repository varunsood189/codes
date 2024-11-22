import numpy as np 
import math
def svd_2x2_singular_values(A: np.ndarray) -> tuple:
	U= A.T.dot(A)
	theta= 0.5*math.atan2(2*U[0][1],U[0][0]-U[1][1])
	J=np.array([[np.cos(theta),-np.sin(theta)],[np.sin(theta),np.cos(theta)]])
	U=J.T.dot(U).dot(J) 
	A_prime = 	np.sqrt(np.diagonal(U))
	SVD =J,A_prime,J.T
	return SVD
