import numpy as np
features = [[1.0, 2.0], [2.0, 1.0], [-1.0, -2.0]]
labels = [1, 0, 0]
initial_weights = [0.1, -0.2]
initial_bias = 0.0
learning_rate = 0.1
epochs = 2
# output: updated_weights = [0.1036, -0.1425]
# updated_bias = -0.0167
# mse_values =[0.3033, 0.2942]

def sig(value):
    return 1/(1+np.exp(-value)) 
def train_neuron(features: np.ndarray, labels: np.ndarray, initial_weights: np.ndarray, initial_bias: float, learning_rate: float, epochs: int) -> (np.ndarray, float, list[float]):
    features = np.array(features)
    mse_values=[]
    for i in range(epochs):
        output = sig(np.matmul(features,initial_weights)+initial_bias)
        mse = np.mean((output- labels)**2)
        mse_values += [mse]
        error = output - labels
        delta_weights = 2/len(labels)*np.dot(features.T, error *output*(1-output))
        updated_weights = initial_weights - learning_rate * delta_weights
        delta_bias = 2/len(labels)* error *output*(1-output)
        updated_bias = initial_bias  - np.sum(learning_rate * delta_bias)
        initial_weights = updated_weights 
        initial_bias = updated_bias
    updated_weights = [round(value,4) for value in updated_weights] 
    updated_bias = round(updated_bias,4)
    mse_values = [round(value,4) for value in mse_values] 
    return updated_weights, updated_bias, mse_values
	
print(train_neuron(features, labels, initial_weights, initial_bias,learning_rate, epochs))
