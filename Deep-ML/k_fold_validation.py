import numpy as np
def cross_validation_split(data: np.ndarray, k: int, seed=42) -> list:
	np.random.seed(seed)
	np.random.shuffle(data)
	n,m = data.shape
	sub_size = int(np.ceil(n / k))
	id_s = np.arange(0, n, sub_size)
	id_e = id_s + sub_size
	if id_e[-1] > n: id_e[-1] = n
	return [[np.concatenate([data[: id_s[i]], data[id_e[i]:]], axis=0).tolist(), data[id_s[i]: id_e[i]].tolist()] for i in range(k)]
