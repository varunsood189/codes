import numpy as np
from itertools import combinations_with_replacement

def polynomial_features(X, degree):
	# Your code here
	n_samples, n_features = np.shape(X)
	vectors = [combinations_with_replacement(range(n_features), i) for i in range(0,degree+1)]
	data = [item for items in vectors for item in items ] 
	X_new = np.empty((n_samples,len(data)))
	for i,it in enumerate(data):
	    X_new[:,i]= np.prod(X[:,it],axis=1)
	return X_new
	
