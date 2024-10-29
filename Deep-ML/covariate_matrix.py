
import numpy as npimport numpy as np
def calculate_covariance_matrix(vectors: list[list[float]]) -> list[list[float]]:
    n_features = len(vectors)
    n_obs= len(vectors[0])
    covariance_matrix = [[0 for _ in range(n_features)] for _ in range(n_features)]
    means = [sum(vector)/n_obs for vector in vectors]
    for i in range(n_features):
        for j in range(i,n_features):
            covariance = sum((vectors[i][k]-means[i])*(vectors[j][k]-means[j]) for k in range(n_obs))/(n_obs-1)
            covariance_matrix[i][j]=covariance_matrix[j][i]=covariance
    return covariance_matrix

	
calculate_covariance_matrix(vectors)
# vectors = [[1, 2, 3], [4, 5, 6]]
# output = [[1.0, 1.0], [1.0, 1.0]]
