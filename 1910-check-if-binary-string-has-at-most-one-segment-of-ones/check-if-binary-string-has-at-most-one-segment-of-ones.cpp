class Solution {
public:
    bool checkOnesSegment(string& s) {
        const int n=s.size();
        int i0=s.find('0');
        if (i0==-1) return 1;
        int i1=s.find_last_of('1');
        return i0>i1;
    }
};