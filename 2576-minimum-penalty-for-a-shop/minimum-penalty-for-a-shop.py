class Solution(object):
    def bestClosingTime(self, customers):
        """
        :type customers: str
        :rtype: int
        """
        n = len(customers)
        
        # Count total 'Y' in the string
        total_y = customers.count('Y')
        
        min_penalty = total_y  # If we close at hour 0
        best_hour = 0
        y_seen = 0  # Count of 'Y' we've passed
        n_seen = 0  # Count of 'N' we've passed
        
        # Try closing at each hour from 1 to n
        for i in range(n):
            if customers[i] == 'Y':
                y_seen += 1
            else:
                n_seen += 1
            
            # Penalty if we close at hour i+1
            # = N's before (including current) + Y's after (excluding current)
            penalty = n_seen + (total_y - y_seen)
            
            if penalty < min_penalty:
                min_penalty = penalty
                best_hour = i + 1
        
        return best_hour