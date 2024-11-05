import numpy as np
# log(sigma_q/sigma_p) +( sigma_p^2+(mean_p-mean_q)^2)/2/sigma_q^2 -1/2
def kl_divergence_normal(mu_p, sigma_p, mu_q, sigma_q):
	return np.log(sigma_q/sigma_p)+(np.square(sigma_p)+np.square(mu_p-mu_q))/2/np.square(sigma_q)-1/2
