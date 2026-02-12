int freq[26]={0};
class Solution {
public:
    static int longestBalanced(string& s) {
        int cnt=1, n=s.size();
        for(int l=0; l<n; l++){
            memset(freq, 0, sizeof(freq));
            int uniq=0, maxF=0, cntMax=0;
            for(int r=l; r<n; r++){
                int f=++freq[s[r]-'a'];
                uniq+=(f==1);
                if (f>maxF){ maxF=f; cntMax=1; }
                else if (f==maxF) cntMax++;
                if (uniq==cntMax) 
                    cnt=max(cnt, r-l+1);
            }
        }
        return cnt;
    }
};
