import numpy as np

def reshape_matrix(a: list[list[int|float]],\
				   new_shape: tuple[int, int]) -> list[list[int|float]]:
	#Write your code here and return a python list after reshaping by using numpy's tolist() method
	reshaped_matrix = np.array(a).reshape(new_shape)
	return reshaped_matrix.tolist()
