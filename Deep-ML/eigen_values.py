import math 
def calculate_eigenvalues(matrix: list[list[float|int]]) -> list[float]:
	a1,b1,c1,d1 = [value for row in matrix for value in row]
	tr,det = -1*(a1+d1),a1*d1-b1*c1
	a,b,c=1,tr,det
	eigenvalues = [(-b+math.sqrt(b**2-4*a*c))/2/a,(-b-math.sqrt(b**2-4*a*c))/2/a]
	return eigenvalues
