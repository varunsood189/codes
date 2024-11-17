import numpy as np
def adam_optimizer(f, grad, x0, learning_rate=0.001, beta1=0.9, beta2=0.999, epsilon=1e-8, num_iterations=10):
	m0=np.zeros_like(x0)
	v0=np.zeros_like(x0)
	for  t in range(1,num_iterations+1):
	    g = grad(x0)
	    mt= beta1*m0 +(1-beta1)*g
	    vt= beta2*v0 +(1-beta2)*g**2
	    mt_=mt/(1-beta1**t)
	    vt_=vt/(1-beta2**t)
	    xt=x0-learning_rate*mt_/(np.sqrt(vt_)+epsilon)
	    m0,v0,x0=mt,vt,xt
	# Your code here
	return x0
