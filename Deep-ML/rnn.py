import numpy as np
def rnn_forward(input_sequence: list[list[float]], initial_hidden_state: list[float], Wx: list[list[float]], Wh: list[list[float]], b: list[float]) -> list[float]:
	# Your code here
	input_sequence =np.array(input_sequence)
	initial_hidden_state =np.array(initial_hidden_state)
	Wx=np.array(Wx)
	Wh=np.array(Wh)
	b=np.array(b)	
	hidden_state = initial_hidden_state
	for data in input_sequence:
		hidden_state = np.tanh(Wx.dot(data)+Wh.dot(hidden_state)+b)
	final_hidden_state=np.round(hidden_state,4)
	return final_hidden_state.tolist()
