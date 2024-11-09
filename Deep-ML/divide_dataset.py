import numpy as np

def divide_on_feature(X, feature_i, threshold):
	# Your code here
	array1 = [data for data in X if data[feature_i]<threshold]
	array2 = [data for data in X if data[feature_i]>=threshold]
	
	return [array2,array1]
