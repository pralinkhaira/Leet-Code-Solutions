
class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        // Create an unordered_map to map group sizes to lists of people's indices.
        unordered_map<int, vector<int>> groupMap;

        // Iterate through the groupSizes vector.
        for (int i = 0; i < groupSizes.size(); i++) {
            // Add the current person's index to the corresponding group size in the map.
            groupMap[groupSizes[i]].push_back(i);
        }

        // Initialize a vector to store the final result.
        vector<vector<int>> result;

        // Iterate through the entries in the groupMap.
        for (auto entry : groupMap) {
            int j = 0;

            // While there are remaining people in this group size.
            while (j < entry.second.size()) {
                vector<int> temp;

                // Create a group of size 'entry.first' and add people to it.
                for (int x = 0; x < entry.first; x++) {
                    int index = entry.second[j];
                    temp.push_back(index);
                    j++;
                }

                // Add the group to the final result.
                result.push_back(temp);
            }
        }

        // Return the final list of groups.
        return result;
    }
};
