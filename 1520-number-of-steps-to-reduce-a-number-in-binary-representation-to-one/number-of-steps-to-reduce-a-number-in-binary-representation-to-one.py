class Solution:
    def numSteps(self, s: str) -> int:
        n = len(s)
        ans = n - 1
        carry = 0

        for i in range(n - 1, 0, -1):
            bit = int(s[i]) + carry

            if bit == 1:
                ans += 1
                carry = 1

        return ans + carry