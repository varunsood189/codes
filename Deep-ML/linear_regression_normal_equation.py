# (INVERSE(X.T*X)*X.T)*y
import numpy as np
def linear_regression_normal_equation(X: list[list[float]], y: list[float]) -> list[float]:
	# Your code here, make sure to round
	X=np.array(X)
	transpose = X.T
	theta=np.matmul(np.matmul(np.linalg.inv(np.matmul(transpose,X)),transpose),y)
	return np.round(theta,4).flatten()
