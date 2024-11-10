import numpy as np

def compressed_row_sparse_matrix(dense_matrix):
	"""
	Convert a dense matrix to its Compressed Row Sparse (CSR) representation.

	:param dense_matrix: 2D list representing a dense matrix
	:return: A tuple containing (values array, column indices array, row pointer array)
	"""
	val = []
	row = [0]
	col = []
	for r in dense_matrix:
		for j,value in enumerate(r):
			if value!=0:
				val+=[value]				
				col+=[j]
		row+=[len(val)]
	return val,col,row 
