import numpy as np
def recall(y_true, y_pred):
	tp =sum((y_true==1) & (y_pred==1))
	fn =sum((y_true==1) & (y_pred==0))
	recall  = tp/(tp+fn)
	return recall
