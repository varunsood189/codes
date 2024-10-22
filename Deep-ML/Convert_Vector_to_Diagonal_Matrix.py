import numpy as np

def make_diagonal(x):
	# Your code here
	answer = np.zeros((len(x),len(x)))
	answer[range(len(x)),range(len(x))]=x
	return answer
