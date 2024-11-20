def inverse_2x2(matrix: list[list[float]]) -> list[list[float]]:
	a,b,c,d = [val for value in matrix for val in value]
	det = a*d-b*c	
	inverse   = [[d/det,-b/det],[-c/det,a/det]]
	return inverse
