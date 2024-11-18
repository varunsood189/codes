import numpy as np

def dice_score(y_true, y_pred):
	# Write your code here
	tp = sum((y_true==1) & (y_pred==1))
	fp =  sum((y_true==0) & (y_pred==1))
	fn =  sum((y_true==1) & (y_pred==0))
	res = 2*tp/(2*tp+fp+fn)
	return round(res, 3)
