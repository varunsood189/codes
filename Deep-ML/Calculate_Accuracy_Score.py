import numpy as np

def accuracy_score(y_true, y_pred):
	# Your code here
	return sum(y_true==y_pred)/len(y_true)
