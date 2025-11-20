class Solution {
public:
    static int intersectionSizeTwo(vector<vector<int>>& I) {
        sort(I.begin(), I.end(), [](vector<int>& X, vector<int>& Y){ 
            const int x0=X[0], x1=X[1], y0=Y[0], y1=Y[1]; 
            return (x1==y1)?x0>y0:x1<y1; 
        });

        int cnt=2, n=I.size();
        int b=I[0][1], a=b-1;
        for (int i=1; i<n; i++) {
            const int L=I[i][0], R=I[i][1];
            if (a>=L) continue;
            const bool NO=L>b;
            cnt+=1+NO;
            a=(NO)?R-1:b;
            b=R;
        }
        return cnt;
    }
};

