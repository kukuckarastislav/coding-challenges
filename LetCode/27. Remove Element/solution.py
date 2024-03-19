class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        i = 0
        while True:
            if i >= len(nums):
                break
            elif nums[i] == val:
                nums.pop(i)
            else:
                i+=1

        return len(nums)
        