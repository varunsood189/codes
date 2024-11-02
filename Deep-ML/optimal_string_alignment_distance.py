def OSA(source: str, target: str) -> int:
    source_len,target_len = len(source), len(target)
    distance_matrix = [ [0 for j in range(target_len+1) ] for i in range(source_len+1) ]
    for i in range(source_len+1):
        distance_matrix[i][0]=i
    for j in range(target_len+1):
        distance_matrix[0][j]=j
        
    for i in range(1,source_len+1):
        for j in range(1,target_len+1):
            distance_matrix[i][j]=min(
                distance_matrix[i-1][j]+1, # deletion 
                distance_matrix[i][j-1]+1, # insertion
                distance_matrix[i-1][j-1]+(1 if source[i-1]!= target[j-1] else 0), # substituion
                ) 
        if i>1 and j>1 and source[i-1]==target[j-2] and source[i-2]==target[j-1]: # transpose
            distance_matrix[i][j]=min(distance_matrix[i][j],distance_matrix[i-2][j-2]+1)
            
    # print(distance_matrix)
    return distance_matrix[-1][-1]
	# Your code here
