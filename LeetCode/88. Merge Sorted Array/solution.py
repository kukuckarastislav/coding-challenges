class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        i1 = 0
        for i2, x2 in enumerate(nums2):
            while nums1[i1] < x2 and i1-i2 < m:
                i1 += 1
            nums1.insert(i1, x2)
            i1 += 1
        for i in range(n):
            nums1.pop()
