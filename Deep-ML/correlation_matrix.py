import numpy as np

def calculate_correlation_matrix(X, Y=None):
	# Your code here
	n_samples = X.shape[0]
	sd_x= np.sqrt(np.mean((X - X.mean(0))**2, axis=0))
	sd_x =np.expand_dims(sd_x,axis=1)
	mean_x= np.mean(X,axis=0)
# 	1/n * ((x-xmean)/sdx/sdy)
	if Y is None:
	    result =1/n_samples*np.divide((X-mean_x).T.dot(X-mean_x),sd_x.dot(sd_x.T))
	else:
	    sd_y= np.sqrt(np.mean((Y - Y.mean(0))**2, axis=0))
	    sd_y =np.expand_dims(sd_y,axis=1)
	    mean_y= np.mean(Y,axis=0)
	    result =1/n_samples*(X-mean_x).T.dot(Y-mean_y)/sd_x.dot(sd_y.T)
	return result
