class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector<string> result;
        
        // Map to store business line priority
        unordered_map<string, int> priority;
        priority["electronics"] = 0;
        priority["grocery"] = 1;
        priority["pharmacy"] = 2;
        priority["restaurant"] = 3;
        
        // Valid business lines set
        unordered_set<string> validLines = {"electronics", "grocery", "pharmacy", "restaurant"};
        
        // Collect valid coupons
        vector<pair<int, string>> validCoupons; // {priority, code}
        
        for (int i = 0; i < code.size(); i++) {
            // Check if coupon is active
            if (!isActive[i]) continue;
            
            // Check if business line is valid
            if (validLines.find(businessLine[i]) == validLines.end()) continue;
            
            // Check if code is non-empty and contains only alphanumeric and underscore
            if (code[i].empty()) continue;
            
            bool validCode = true;
            for (char c : code[i]) {
                if (!isalnum(c) && c != '_') {
                    validCode = false;
                    break;
                }
            }
            
            if (!validCode) continue;
            
            // Add to result
            validCoupons.push_back({priority[businessLine[i]], code[i]});
        }
        
        // Sort by priority first, then by code lexicographically
        sort(validCoupons.begin(), validCoupons.end(), [](const pair<int, string>& a, const pair<int, string>& b) {
            if (a.first != b.first) {
                return a.first < b.first;
            }
            return a.second < b.second;
        });
        
        // Extract codes
        for (const auto& coupon : validCoupons) {
            result.push_back(coupon.second);
        }
        
        return result;
    }
};