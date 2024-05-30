class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        
        n = len(nums)
        triplets = []
        if n < 3:
            return triplets
        
        nums.sort()

        for i in range(0, n-2):

            if nums[i] > 0:
                break

            if i > 0 and nums[i] == nums[i-1]:
                continue

            j = i+1
            k = n-1

            while j < k:
                numsI = nums[i]
                numsJ = nums[j]
                numsK = nums[k]
                s = numsI + numsJ + numsK

                if s > 0:
                    k -= 1
                elif s < 0:
                    j += 1

                else:
                    triplets.append((numsI, numsJ, numsK))

                    tempJ = numsJ
                    tempK = numsK
                    while j < k and nums[j] == tempJ:
                        j += 1
                    while j < k and nums[k] == tempK:
                        k -= 1

        return triplets
    
