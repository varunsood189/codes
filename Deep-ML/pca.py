import numpy as np
data = np.array([[4,2,1],[5,6,7],[9,12,1],[4,6,7]])
k = 2
def pca(data: np.ndarray, k: int) -> list[list[int|float]]:
    # Your code here
    standardised = (data-np.mean(data,axis=0))/np.std(data,axis=0)
    covariance_matrix = np.cov(standardised,rowvar=False)
    eigenvalues, eigenvectors = np.linalg.eig(covariance_matrix)
    idx = np.argsort(eigenvalues)[::-1]
    sort_eigenvectors = eigenvectors[:,idx]
    principal_components = sort_eigenvectors[:,:k]
    print(eigenvalues[idx])
    return principal_components
print(pca(data, k) )
