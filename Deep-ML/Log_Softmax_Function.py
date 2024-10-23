import numpy as np

def log_softmax(scores: list) -> np.ndarray:
	# Your code
	scores= scores - np.max(scores)
	scores =scores -  np.log(sum(np.exp(scores)))
	return scores
