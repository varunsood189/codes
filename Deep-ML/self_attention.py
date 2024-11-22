import numpy as np
def compute_qkv(X, W_q, W_k, W_v):
	Q=X.dot(W_q)
	K=X.dot(W_k)
	V=X.dot(W_v)	
	return Q,K,V
def self_attention(Q, K, V):
	x = Q.dot(K.T)/np.sqrt(K.shape[1])
	softmax = np.exp(x)/np.sum(np.exp(x), axis=1, keepdims=True)
	attention_output = softmax.dot(V)
	return attention_output
