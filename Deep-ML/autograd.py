class Value:
	def __init__(self, data, _children=(), _op=''):
		self.data = data
		self.grad = 0
		self._backward = lambda: None
		self._prev = set(_children)
		self._op = _op
	def __repr__(self):
		return f"Value(data={self.data}, grad={self.grad})"

	def __add__(self, other):
		 # Implement addition here
		other = other if isinstance(other,Value) else Value(other)
		out = Value(self.data+other.data,(self,other),'+')
		def _backward():
			self.grad += out.grad
			other.grad += out.grad
		out._backward =_backward
		return out
	
	def __mul__(self, other):
		# Implement multiplication 
		other = other if isinstance(other,Value) else Value(other)
		out = Value(self.data*other.data,(self,other),'*')
		def _backward():
			self.grad += other.data*out.grad
			other.grad += self.data*out.grad
		out._backward =_backward
		return out

	def relu(self):
		out = Value(self.data if self.data>0 else 0, (self,), 'ReLU')
		def _backward():
			self.grad += (out.data>0)*out.grad
		out._backward =_backward
		return out
	def backward(self):
		# Implement backward pass here
		topo =[]
		visited = set()
		def build_topo(v):
			if v not in visited:
				visited.add(v)
				for child in v._prev:
					build_topo(child)
				topo.append(v)
		build_topo(self)
		self.grad=1
		for value in reversed(topo):
			value._backward()
		
