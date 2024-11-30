import numpy as np

def l1_regularization_gradient_descent(X: np.array, y: np.array, alpha: float = 0.1, learning_rate: float = 0.01, max_iter: int = 1000, tol: float = 1e-4) -> tuple:
	n_samples, n_features = X.shape

	weights = np.zeros(n_features)
	bias = 0
	for i in range(max_iter):
	    predictions = X.dot(weights)+bias
	    error =predictions-y 
	    dj_dw = (X.T.dot(error)/n_samples+alpha*np.sign(weights))
	    dj_db =  np.sum(error)/n_samples
	    weights-=learning_rate*dj_dw
	    bias-=learning_rate*dj_db
	    if np.linalg.norm(dj_dw,ord=1)<tol:
	        break
	# Your code here
	return weights,bias
