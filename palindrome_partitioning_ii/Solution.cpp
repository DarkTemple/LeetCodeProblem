class Solution {
public:
    int minCut(string s)
    {
        bool isPalTable[s.length()][s.length()];
        memset(isPalTable, 0, sizeof(isPalTable));
        for (int i=0; i<s.length(); i++) {
            for (int j=i; j>=0; j--) {
                if (s[i] == s[j] && (i-j <= 1 || isPalTable[j+1][i-1])) {
                    isPalTable[j][i] = true;
                }
            }
        }
        
        int dpTable[s.length()];
        for (int i=(int)s.length()-1; i>=0; i--) {
            int minSplit = INT_MAX;
            for (int j=i; j<s.length(); j++) {
                if (isPalTable[i][j]) {
                    if (j == s.length()-1) {
                        minSplit = 0;
                    } else {
                        minSplit = min(minSplit, 1+dpTable[j+1]);
                    }
                }
            }
            
            dpTable[i] = minSplit;
        }
        
        return dpTable[0];
    }
};