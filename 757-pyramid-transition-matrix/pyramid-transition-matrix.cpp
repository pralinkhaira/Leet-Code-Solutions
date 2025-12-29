class Solution {
private:
    unordered_map<string, vector<char>> allowedMap;
    unordered_map<string, bool> memo;
    
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        // Build a map: key is two characters, value is vector of possible tops
        for(const string& pattern : allowed) {
            string key = pattern.substr(0, 2);
            allowedMap[key].push_back(pattern[2]);
        }
        return canBuild(bottom);
    }
    
private:
    bool canBuild(string current) {
        if(current.length() == 1) {
            return true;
        }
        
        // Check memo
        if(memo.find(current) != memo.end()) {
            return memo[current];
        }
        
        string next = "";
        bool result = buildLevel(current, 0, next);
        memo[current] = result;
        return result;
    }
    
    bool buildLevel(const string& current, int pos, string next) {
        // If we've processed all adjacent pairs, move to next level
        if(pos == current.length() - 1) {
            return canBuild(next);
        }
        
        // Get left and right blocks
        string key = "";
        key += current[pos];
        key += current[pos + 1];
        
        // Check if this pair has valid tops
        if(allowedMap.find(key) == allowedMap.end()) {
            return false;
        }
        
        // Try each valid top block
        for(char top : allowedMap[key]) {
            if(buildLevel(current, pos + 1, next + top)) {
                return true;
            }
        }
        
        return false;
    }
};