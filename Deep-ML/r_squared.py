import numpy as np

def r_squared(y_true, y_pred):
	# Write your code here
	y_meam = np.mean(y_true)
	
	return 1 -  sum(np.square(y_true - y_pred))/sum(np.square( y_true-y_meam))
