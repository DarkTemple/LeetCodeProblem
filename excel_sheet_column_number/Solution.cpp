class Solution {
public:
    int titleToNumber(string s) {
        int retNumber = 0;
        for (int i=0; i<s.length(); i++) {
            int val = s[i] - 'A' + 1;
            retNumber = retNumber * 26 + val;
        }
        
        return retNumber;
    }
};