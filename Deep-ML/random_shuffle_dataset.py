import numpy as np
import random
def shuffle_data(X, y, seed=None):
	# Your code here
	if seed !=None:	
		np.random.seed(seed)
	idx = np.random.permutation(range(len(y)))
	return X[idx],y[idx]
