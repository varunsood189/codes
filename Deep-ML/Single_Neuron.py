import math
import numpy as np
def single_neuron_model(features: list[list[float]], labels: list[int], weights: list[float], bias: float) -> (list[float], float):
	# Your code here

	mse=[]
	probabilities=[]
	for feature,label in zip(features,labels):
		probability=0
		probability =1/(1+math.exp(-(np.dot(weights,feature)+bias)))
		mse += [(probability - label)**2 ]
		probabilities+=[round(probability,4)]
	return probabilities, round(sum(mse)/len(mse),4)
