import numpy as np
def translate_object(points, tx, ty):
	points = np.array(points)
	#print(points[:,0])
	points[:,0]+=tx
	points[:,1]+=ty
	translated_points =points 
	return translated_points
