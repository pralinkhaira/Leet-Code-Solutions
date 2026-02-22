class Solution {
    func binaryGap(_ n: Int) -> Int {
        var n = n
        var last = -1
        var maxGap = 0
        var position = 0
        
        while n > 0 {
            if (n & 1) == 1 {
                if last != -1 {
                    maxGap = max(maxGap, position - last)
                }
                last = position
            }
            n >>= 1
            position += 1
        }
        
        return maxGap
    }
}