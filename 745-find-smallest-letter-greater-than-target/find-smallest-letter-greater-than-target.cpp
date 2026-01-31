class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        const int size = letters.size();
        int i = 0, j = size - 1, resultIdx = -1;
        while(i <= j){
            int mid = i + (j - i)/2;
            if (letters[mid] > target){resultIdx = mid; j = mid - 1;}
            else i = mid + 1;
        } return (resultIdx == -1? letters[0] : letters[resultIdx]);
    }
};