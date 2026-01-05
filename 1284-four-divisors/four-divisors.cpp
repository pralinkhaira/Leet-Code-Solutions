class Solution {
private:
    int countDivisors(int n) {
        int count = 0;
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                if (i * i == n) {
                    count++;
                } else {
                    count += 2;
                }
            }
        }
        return count;
    }
    
    int sumDivisors(int n) {
        int sum = 0;
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                sum += i;
                if (i * i != n) {
                    sum += n / i;
                }
            }
        }
        return sum;
    }
    
public:
    int sumFourDivisors(vector<int>& nums) {
        int result = 0;
        
        for (int num : nums) {
            int divisorCount = countDivisors(num);
            if (divisorCount == 4) {
                result += sumDivisors(num);
            }
        }
        
        return result;
    }
};