import numpy as np

def to_categorical(x, n_col=None):
	# Your code here
	if n_col==None:
		n_col = len(set(x))
		
	answer = np.zeros((len(x),n_col))
	answer[range(len(x)),x] = 1
	return answer
