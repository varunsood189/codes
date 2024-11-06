import numpy as np

def ridge_loss(X: np.ndarray, w: np.ndarray, y_true: np.ndarray, alpha: float) -> float:
	# Your code here
	return np.mean((np.matmul(X,w)-y_true)**2) + alpha*np.sum(w**2)
