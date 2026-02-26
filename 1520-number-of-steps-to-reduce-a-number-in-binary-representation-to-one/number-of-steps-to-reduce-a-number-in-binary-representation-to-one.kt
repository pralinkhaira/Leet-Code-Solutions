class Solution {
    fun numSteps(s: String): Int {
        val n = s.length
        var ans = n - 1
        var carry = 0

        for (i in n - 1 downTo 1) {
            val bit = (s[i] - '0') + carry

            if (bit == 1) {
                ans++
                carry = 1
            }
        }

        return ans + carry
    }
}