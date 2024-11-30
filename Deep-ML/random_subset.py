import numpy as np

def get_random_subsets(X, y, n_subsets, replacements=True, seed=42):
	# Your code here
	np.random.seed(seed)
	n,m = X.shape
	subset_size = n if replacements else n//2
	idx = [np.random.choice(n,subset_size,replace = replacements) for i in range(n_subsets)]
	return [(X[idx][i].tolist(),y[idx][i].tolist()) for i in range(n_subsets)]
