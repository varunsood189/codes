import numpy as np
def update_centroid(assignment,points,centroids):
	for i in range(len(centroids)):
		centroids[i] = np.average(points[assignment==i],axis=0)
	return centroids
def calculate_distance(k,points,centroids):
	distances = np.zeros((k,len(points)))
	for i,centroid in enumerate(centroids):		
		distances[i,:] = np.sum(np.square(points-centroid),axis=1)	
	return distances
def k_means_clustering(points: list[tuple[float, float]], k: int, initial_centroids: list[tuple[float, float]], max_iterations: int) -> list[tuple[float, float]]:
	# Your code here
	points=  np.array(points)
	centroids=  initial_centroids
	for itr in range(max_iterations):
		distances = calculate_distance(k,points,centroids)
		centroids = update_centroid(np.argmin(distances,axis=0),points,centroids)
	final_centroids=centroids
	return final_centroids

# points = [(1, 2), (1, 4), (1, 0), (10, 2), (10, 4), (10, 0)]
# k = 2
# initial_centroids = [(1, 1), (10, 1)]
# max_iterations = 10
# print(k_means_clustering(points,k, \
# initial_centroids, max_iterations))
