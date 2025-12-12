class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        // Sort events by timestamp, then by type (OFFLINE before MESSAGE)
        sort(events.begin(), events.end(), [](const vector<string>& a, const vector<string>& b) {
            int timeA = stoi(a[1]);
            int timeB = stoi(b[1]);
            if (timeA != timeB) return timeA < timeB;
            // OFFLINE events come before MESSAGE events at same timestamp
            return a[0] == "OFFLINE";
        });
        
        vector<int> mentions(numberOfUsers, 0);
        set<int> offlineUsers;
        map<int, int> offlineUntil; // user id -> time they come back online
        
        for (const auto& event : events) {
            string type = event[0];
            int timestamp = stoi(event[1]);
            
            if (type == "OFFLINE") {
                int userId = stoi(event[2]);
                offlineUntil[userId] = timestamp + 60;
                offlineUsers.insert(userId);
            } else {
                // MESSAGE event
                // First, update online status based on offlineUntil
                vector<int> toRemove;
                for (int userId : offlineUsers) {
                    if (offlineUntil[userId] <= timestamp) {
                        toRemove.push_back(userId);
                    }
                }
                for (int userId : toRemove) {
                    offlineUsers.erase(userId);
                }
                
                string mentions_string = event[2];
                
                if (mentions_string == "ALL") {
                    // Mention all users
                    for (int i = 0; i < numberOfUsers; i++) {
                        mentions[i]++;
                    }
                } else if (mentions_string == "HERE") {
                    // Mention only online users
                    for (int i = 0; i < numberOfUsers; i++) {
                        if (offlineUsers.find(i) == offlineUsers.end()) {
                            mentions[i]++;
                        }
                    }
                } else {
                    // Parse specific IDs
                    stringstream ss(mentions_string);
                    string id_str;
                    while (ss >> id_str) {
                        // Remove "id" prefix
                        int userId = stoi(id_str.substr(2));
                        mentions[userId]++;
                    }
                }
            }
        }
        
        return mentions;
    }
};