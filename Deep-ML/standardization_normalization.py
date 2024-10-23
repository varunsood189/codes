import numpy as np
def feature_scaling(data: np.ndarray) -> (np.ndarray, np.ndarray):
	# Your code here
	#standardization is 0 mean and 1 sd
	# norm is 0-1 range
	standardized_data = (data - np.mean(data,axis=0))/np.std(data,axis=0)
	normalized_data = (data-np.min(data,axis=0))/(np.max(data,axis=0)-np.min(data,axis=0))
	return standardized_data, normalized_data
