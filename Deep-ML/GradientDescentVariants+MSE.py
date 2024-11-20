import numpy as np
# prediction  = x.dot(weights)
# error = predictions - y 
# gradient = 2/m*error*x
# weight-=learning_rate*gradient
def gradient_descent(X, y, weights, learning_rate, n_iterations, batch_size=1, method='batch'):
	# Your code here
	m=len(y)
	if method =="batch":
	    for _ in range(n_iterations):
	        weights -= learning_rate*2/m*np.matmul(np.matmul(X,weights)-y,X)
	    return weights
	if method =="stochastic":
	    for _ in range(n_iterations):
	        for x_data,y_data in zip(X,y):
	            weights -= learning_rate*2*x_data.T.dot(x_data.dot(weights)-y_data)
	    return weights
	if method =="mini_batch":
	    for _ in range(n_iterations):
	        for start in range(0,m,batch_size):
	            x_data = X[start:start+batch_size]
	            y_data = y[start:start+batch_size] 
	            weights -= learning_rate*2/batch_size*x_data.T.dot(x_data.dot(weights)-y_data)
	    return weights
