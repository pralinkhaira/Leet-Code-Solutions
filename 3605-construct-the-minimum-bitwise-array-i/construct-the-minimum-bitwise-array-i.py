class Solution:
    def minBitwiseArray(self, nums: List[int]) -> List[int]:
        result = []
        for num in nums:
            found = False
            # Try all possible values from 0 to num-1
            for x in range(num):
                if (x | (x + 1)) == num:
                    result.append(x)
                    found = True
                    break
            if not found:
                result.append(-1)
        return result