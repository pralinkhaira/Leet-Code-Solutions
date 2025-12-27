class Solution {
public:
    int getMaxi(vector<long long> &vis, int &n){
        int maxi = 0, maxiIDX = 0;
        for(int i=0; i<n; i++){
            if(vis[i] > maxi){
                maxi = vis[i]; maxiIDX = i;
            }
        }
        return maxiIDX;
    }

    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        vector<long long> rooms(n, 0), vis(n, 0);

        for(auto &meet : meetings){
            int start = meet[0], end = meet[1];
            bool flag = false;
            long long mini = LLONG_MAX, miniIdx = 0;

            for(int i=0; i<n; i++){
                if(rooms[i] <= start){
                    rooms[i] = end;
                    vis[i]++;
                    flag = true;
                    break;
                }

                if(rooms[i] < mini){
                    mini = rooms[i];
                    miniIdx = i;
                }
            }

            // If all rooms are occupied for current meet
            if(flag == false){
                rooms[miniIdx] += end - start;
                vis[miniIdx]++;
            }
        }

        // Get room having highest meetings
        int ans = getMaxi(vis, n);
        return ans;
    }
};