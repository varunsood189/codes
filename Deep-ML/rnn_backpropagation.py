import numpy as np
import math
class SimpleRNN:
	def __init__(self, input_size, hidden_size, output_size):
		"""
		Initializes the RNN with random weights and zero biases.
		"""
		self.hidden_size = hidden_size
		self.W_xh = np.random.randn(hidden_size, input_size)*0.01
		self.W_hh = np.random.randn(hidden_size, hidden_size)*0.01
		self.W_hy = np.random.randn(output_size, hidden_size)*0.01
		self.b_h = np.zeros((hidden_size, 1))
		self.b_y = np.zeros((output_size, 1))
		self.h =  np.zeros((hidden_size, 1))
		self.y = 0
	def forward(self, x):
		"""
		Forward pass through the RNN for a given sequence of inputs.
		"""
		h = np.zeros((self.hidden_size,1))
		outputs =[]
		self.last_inputs =[]
		self.last_hidden =[h]
		
		for t in range(len(x)):
		    self.last_inputs.append(x[t].reshape(-1,1))
		    h = np.tanh(self.W_xh.dot(self.last_inputs[t])+self.W_hh.dot(h)+self.b_h)
		    y = self.W_hy.dot(h)+self.b_y
		    outputs.append(y)
		    self.last_hidden.append(h)
		self.last_outputs = outputs	    
		return np.array(outputs)
		
	def backward(self, x, y, learning_rate):
		"""
		Backpropagation through time to adjust weights based on error gradient.
		"""		
		dw_hy=np.zeros_like(self.W_hy)
		dw_hh=np.zeros_like(self.W_hh)
		dw_xh=np.zeros_like(self.W_xh)
		db_y=np.zeros_like(self.b_y)
		db_h=np.zeros_like(self.h)

		dh_next=np.zeros((self.hidden_size,1))
		
		for t in reversed(range(len(x))):
		    dl_dy = self.last_outputs[t] - y[t].reshape(-1,1)
		    
		    dw_hy +=dl_dy.dot(self.last_hidden[t+1].T)
		    db_y +=dl_dy
		    dh = np.dot(self.W_hy.T,dl_dy)+ dh_next
		    dh_raw = (1-self.last_hidden[t+1]**2)*dh
		   
		    dw_xh +=dh_raw.dot(self.last_inputs[t].T)
		    dw_hh +=dh_raw.dot(self.last_hidden[t].T)
		    db_h +=dh_raw 
		    
		    dh_next = self.W_hh.T.dot(dh_raw)
		
		self.W_xh-=learning_rate*dw_xh
		self.W_hh-=learning_rate*dw_hh
		self.W_hy-=learning_rate*dw_hy
		self.b_h-=learning_rate*db_h
		self.b_y-=learning_rate*db_y
		
