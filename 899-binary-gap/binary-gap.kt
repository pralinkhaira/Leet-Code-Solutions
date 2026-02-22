class Solution {
    fun binaryGap(n: Int): Int {
        var num = n
        var last = -1
        var maxGap = 0
        var position = 0

        while (num > 0) {
            if ((num and 1) == 1) {
                if (last != -1) {
                    maxGap = maxOf(maxGap, position - last)
                }
                last = position
            }
            num = num shr 1
            position++
        }

        return maxGap
    }
}