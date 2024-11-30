import numpy as np
def create_hv(dim):
	return np.random.choice([-1,1],dim)

def create_col_hv(dim,seed):
	np.random.seed(seed)
	return create_hv(dim),create_hv(dim)

def bind(hv1,hv2):
	return hv1*hv2

def sign(vector):
	return np.array([1 if v >=0 else -1 for v in vector])
	
def bundle(hvs):
	return sign(np.sum(list(hvs.values()),axis=0))

def create_row_hv(row, dim, random_seeds):
	# Write your code here
	row_hvs = {col:bind(*create_col_hv(dim,random_seeds[col])) for col in row.keys()}
	return bundle(row_hvs)
