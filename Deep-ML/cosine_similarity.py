import numpy as np

def cosine_similarity(v1, v2):
	# Implement your code here
	return np.round(v1.dot(v2)/np.sqrt(v1.dot(v1)*v2.dot(v2)),3)
