import numpy as np

# jaccard_index_binary_classification = intersection(a,b)/union(a,b) 
def jaccard_index(y_true, y_pred):
	# Write your code here
	i = sum((y_true==1) &(y_pred==1))
	u  = sum((y_true==1) |(y_pred==1))
	result = i /u
	return round(result, 3)
