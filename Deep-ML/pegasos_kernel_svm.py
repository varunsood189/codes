import numpy as np
def linear_(x,y):
	return x.dot(y)
def rbf_(x,y,sigma=1.0):
	return np.exp(-np.linalg.norm(x-y)**2/(2*(sigma**2)))

def pegasos_kernel_svm(data: np.ndarray, labels: np.ndarray, kernel='linear', lambda_val=0.01, iterations=100,sigma=1) -> (list, float):
	b=0
	length= data.shape[0]
	alphas= np.zeros(length)
	for t in range(1,iterations+1):
		for i in range(length):
			eta = 1/(lambda_val*t)
			if kernel =="linear":
				  kernel_func=linear_
			if kernel =="rbf":
				  kernel_func=lambda x,y : rbf_(x,y,sigma)
			
			decision =sum(alphas[j]*labels[j]*kernel_func(data[j],data[i]) for j in range(length)) +b
			if labels[i]*decision <1:
				  alphas[i]+=eta*(labels[i]-lambda_val*alphas[i])
				  b +=eta*labels[i]
			
	return np.round(alphas,4).tolist(), np.round(b,4)
	
