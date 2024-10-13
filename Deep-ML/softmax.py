import math

def softmax(scores: list[float]) -> list[float]:
	# Your code here
	sum_= sum([math.exp(value) for value in scores])
	probabilities = [math.exp(value)/sum_ for value in scores]  
	return probabilities
