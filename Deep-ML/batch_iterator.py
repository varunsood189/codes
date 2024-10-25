import numpy as np

def batch_iterator(X, y=None, batch_size=64):
	samples =X.shape[0]
	batches = []
	for i in range(0,samples//batch_size+1):
		start = i*batch_size
		end = min(start+batch_size,samples)
		if y is None:
			batches.append(X[start:end])
		else:
			batches.append([X[start:end],y[start:end]])
		
	return batches
