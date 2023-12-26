class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        # n^2 complexity 
        dic_ = {}
        for i,num in enumerate(nums):
            if target-num in dic_:
                return [ dic_[target-num], i] 
            else:
                dic_[num] = i
                    
