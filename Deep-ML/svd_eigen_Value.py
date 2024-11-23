import numpy as np

def svd_2x2(A: np.ndarray) -> tuple:
    # Your code here
    y1,x1=A[1,0]+A[0,1],A[0,0]-A[1,1]
    y2,x2=A[1,0]-A[0,1],A[0,0]+A[1,1]
    
    h1=np.sqrt(x1**2+y1**2)
    h2=np.sqrt(x2**2+y2**2)
    
    t1=x1/h1
    t2=x2/h2
    
    cc= np.sqrt((1+t1)*(1+t2))
    ss= np.sqrt((1-t1)*(1-t2))
    cs= np.sqrt((1+t1)*(1-t2))
    sc= np.sqrt((1-t1)*(1+t2))
    
    c1=(cc-ss)/2.0
    s1=(sc+cs)/2.0
    s= np.array([(h1+h2)/2.0,abs(h1-h2)/2.0])
    U = np.array([[-c1,-s1],[-s1,c1]])
    V=np.diag(1.0/s)@U.T @A
    return U,s,V

# approximation error in this code
# import numpy as np

# def svd_2x2(A: np.ndarray) -> tuple:
#     # Your code here
# 	ATA = A.T.dot(A)
# 	AAT = A.dot(A.T)
# 	trace = np.trace(ATA)
# 	det = np.linalg.det(ATA)
# 	e1,e2 = np.roots([1,-(trace),det])
# 	def eigen_vector(A,e1):
# 	    matrix = A - np.eye(2)*e1
# 	    if np.abs(matrix[0][0])>1e-10:
# 	        x2 = 1
# 	        x1 = -1* matrix[0][1]/matrix[0][0]*x2
# 	    else:
# 	        x1 = 1
# 	        x2 = -1*matrix[1][0]/matrix[1][1]*x1
# 	    vector = np.array([x1, x2])
# 	   # print(vector)
# 	    return vector/np.linalg.norm(vector)
	    
# 	V=np.array([eigen_vector(ATA,e1),
# 	eigen_vector(ATA,e2)])
# 	S= np.sqrt(np.abs([e1,e2]))
# 	U= np.zeros(A.shape)
# 	for i in range(len(U)):
# 	    for j in range(len(U[0])):
# 	        temp=0
# 	        for k in range(A.shape[1]):
# 	            temp+= V[k][j]*A[k][i]
# 	        U[i][j]=1/S[j]*temp
# # 	print(U @ np.diag(S) @ V )
# 	return U,S,V
