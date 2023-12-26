class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        max_ = 0
        start = 0
        end =  0 
        dict_={}
        for i,char in enumerate(s):
            if char in dict_:
                start = max(dict_[char]+1,start)
            dict_[char] = i
            end = i 

            if max_ < (end -start+1):
             max_ = (end -start+1)
                
        return max_
