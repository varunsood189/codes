import numpy as np

def transform_matrix(A: list[list[int|float]], T: list[list[int|float]], S: list[list[int|float]]) -> list[list[int|float]]:
	A=np.array(A)
	S=np.array(S)
	T=np.array(T)
	if np.linalg.det(S)==0 or np.linalg.det(T)==0:
		return -1
	transformed_matrix = np.matmul(np.linalg.inv(T),(np.matmul(A,S)))
	return transformed_matrix
