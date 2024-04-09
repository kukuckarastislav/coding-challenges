class Solution:
    def maxArea(self, height: List[int]) -> int:
        n = len(height)
        max_area = 0
        i = 0
        j = n - 1
        
        while i < j:
            hi = height[i]
            hj = height[j]

            area = j - i
            if hi < hj:
                area *= hi
            else:
                area *= hj

            if area > max_area:
                max_area = area

            if hi > hj:
                j -= 1
            else:
                i += 1

        return max_area
    