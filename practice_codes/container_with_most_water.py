class Solution:
    def maxArea(self, height: List[int]) -> int:
        max_ = 0
        l=0
        r=len(height)-1
        while l<r:
            max_ = max(max_,min(height[r],height[l])*(r-l))
            if height[r]<height[l]:
                r-=1
            else:
                l+=1
         
        return max_
