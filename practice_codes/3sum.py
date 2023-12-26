class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        print(nums)
        length= len(nums)
        solution=[]
        for i in range(length-2):
            if (i>0 and nums[i]==nums[i-1]):
                continue
            j  = i+1
            k= length-1            
            while(j<k):
                if nums[i]+nums[j]+nums[k]<0 :
                    j+=1
                elif nums[i]+nums[j]+nums[k]>0:
                    k-=1
                else :
                    # print("i ",[[i],[j],[k]])
                    # print([nums[i],nums[j],nums[k]])
                    solution+=[[nums[i],nums[j],nums[k]]]
                    j+=1
                    k-=1
                    while (j<k and nums[j]==nums[j-1]):
                        j+=1
                    while (j<k and nums[k]==nums[k+1]):                    
                        k-=1
         

        #         sum_[str(i)+":"+str(j)] = - nums[i]-nums[j]
        return solution
