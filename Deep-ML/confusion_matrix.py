def confusion_matrix(data):
	# Implement the function here
	tp=fp=tn=fn=0
	for d in  data:
		if d[0]==d[1]==0:
			tn+=1
		if d[0]==d[1]==1:
			tp+=1
		if d[0]!=d[1] & d[1]==0:
			fn+=1
		if d[0]!= d[1]& d[1]==1:
			fp+=1
	return [[tp,fn], [fp,tn]]

// from collections import Counter

// def confusion_matrix(data):
// 	# Implement the function here
// 	counts = Counter(tuple(pair) for pair in data)
// 	return [[counts[(1,1)],counts[(1,0)]], [counts[(0,1)],counts[(0,0)]]]
