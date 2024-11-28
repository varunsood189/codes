import numpy as np
def compressed_col_sparse_matrix(dense_matrix):
	"""
	Convert a dense matrix into its Compressed Column Sparse (CSC) representation.

	:param dense_matrix: List of lists representing the dense matrix
	:return: Tuple of (values, row indices, column pointer)
	"""
	vals = []
	row_idx = []
	col_ptr =[0]
	for i,row in enumerate(np.array(dense_matrix).T):
		for j,data in enumerate(row):
			if data !=0:
				vals+=[data]
				row_idx+=[j]
		col_ptr+=[len(vals)]
	return 	vals, row_idx, col_ptr
