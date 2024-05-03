class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        v1Arr = version1.split(".")
        v2Arr = version2.split(".")
        n = len(v1Arr)
        m = len(v2Arr)

        for i in range(max(n,m)):
            num1 = int(v1Arr[i]) if i < n else 0
            num2 = int(v2Arr[i]) if i < m else 0

            if num1 < num2:
                return -1
            elif num1 > num2:
                return 1
        
        return 0