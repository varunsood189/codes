import numpy as np
def simple_conv2d(input_matrix: np.ndarray, kernel: np.ndarray, padding: int, stride: int):
	kernel_height, kernel_width = kernel.shape
	input_padded = np.pad(input_matrix, ((padding, padding), (padding, padding)), 'constant')
	input_padded_height, input_padded_width = input_padded.shape
	output_height = int((input_padded_height-kernel_height)/stride+1)
	output_width = int((input_padded_width-kernel_width)/stride+1)
	# Your code here
	output_matrix = np.zeros((output_height,output_width))
	for i in range(output_height):
		for j in range(output_width):
			output_matrix[i][j]=sum(np.multiply(input_padded[i*stride:i*stride+kernel_height,j*stride:j*stride+kernel_width],kernel).flatten())
	return output_matrix
	
