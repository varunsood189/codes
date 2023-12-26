class Solution:
    def longestPalindrome(self, s: str) -> str:
        length = len(s)
        arr = [[0]*(length) for _  in range(length)]
        start = 0        
        maxlength = 0
        
        for i in range(0,length):            
            arr[i][i] = 1            
            start = 0
            maxlength = 1
        for i in range(0,length-1):            
            if s[i]==s[i+1]:
                arr[i][i+1] = 2
                if maxlength <2:   
                    start = i
                    maxlength = 2
                

        for len_ in range(3,length+1):            
            for i in range(length-len_+1):
                j = i + len_-1                
                if(s[i]==s[j] and arr[i+1][j-1]):
                    arr[i][j] = len_
                    if len_>maxlength:
                        start = i
                        maxlength = len_
        return s[start:start+maxlength]

