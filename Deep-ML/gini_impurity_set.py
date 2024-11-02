import numpy as np

def gini_impurity(y):
	"""
	Calculate Gini Impurity for a list of class labels.

	:param y: List of class labels
	:return: Gini Impurity rounded to three decimal places
	"""
	distinct = set(y)
	result = 1
	y=np.array(y)
	for value in distinct:
		result =result - np.square(sum(y==value)/len(y))
	return round(result,3)
