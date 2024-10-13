import numpy as np
def matrix_dot_vector(a:list[list[int|float]],b:list[int|float])-> list[int|float]:
	if len(a[0]) == len(b):
		return np.dot(a,b)
	else:
		return -1
					
