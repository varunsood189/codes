import numpy as np	
def sigmoid(x): return 1 / (1 + np.exp(-x))	
class LSTM:	
	def __init__(self, input_size, hidden_size):	
		self.input_size = input_size	
		self.hidden_size = hidden_size	

		# Initialize weights and biases	
		self.Wf = np.random.randn(hidden_size, input_size + hidden_size)	
		self.Wi = np.random.randn(hidden_size, input_size + hidden_size)	
		self.Wc = np.random.randn(hidden_size, input_size + hidden_size)	
		self.Wo = np.random.randn(hidden_size, input_size + hidden_size)	

		self.bf = np.zeros((hidden_size, 1))	
		self.bi = np.zeros((hidden_size, 1))	
		self.bc = np.zeros((hidden_size, 1))	
		self.bo = np.zeros((hidden_size, 1))	

	def forward(self, x, initial_hidden_state, initial_cell_state):	
		"""	
		Processes a sequence of inputs and returns the hidden states, final hidden state, and final cell state.	
		"""	
		h = initial_hidden_state	
		c= initial_cell_state	
		outputs=[]	
		for t in range(len(x)):	
		    xt = x[t].reshape(-1,1)	
		    hidden_state_x = np.vstack((h,xt))	
		    f_t = sigmoid(np.dot(self.Wf,hidden_state_x)+self.bf)	

		    i_t = sigmoid(np.dot(self.Wi,hidden_state_x)+self.bi)	
		    c_t_ = np.tanh(np.dot(self.Wc,hidden_state_x)+self.bc)	

		    c = f_t*c +i_t*c_t_	

		    o_t = sigmoid(np.dot(self.Wo,hidden_state_x)+self.bo)	

		    h  =o_t*np.tanh(c)	
		    outputs.append(h)	
		return np.array(outputs) ,h,c
