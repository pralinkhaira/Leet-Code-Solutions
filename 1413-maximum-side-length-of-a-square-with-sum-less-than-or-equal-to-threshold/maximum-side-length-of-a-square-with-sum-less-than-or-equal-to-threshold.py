class Solution:
    def maxSideLength(self, mat: List[List[int]], threshold: int) -> int:
        m, n = len(mat), len(mat[0])
        max_side = 0
        
        for i in range(m):
            for j in range(n):
                current_sum = 0
                for side in range(1, min(m-i, n-j) + 1):
                    # Add the new row and column
                    for k in range(side):
                        current_sum += mat[i + side - 1][j + k]
                    for k in range(side - 1):
                        current_sum += mat[i + k][j + side - 1]
                    
                    if current_sum <= threshold:
                        max_side = max(max_side, side)
                    else:
                        break
        
        return max_side