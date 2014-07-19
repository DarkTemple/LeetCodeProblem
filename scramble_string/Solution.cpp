class Solution {
public:
    bool isScramble(string s1, string s2) {
        int len = (int)s1.length();
        bool dpTable[len][len][len+1];
        memset(dpTable, 0, sizeof(dpTable));
        for (int i=len-1; i>=0; i--) {
            for (int j=len-1; j>=0; j--) {
                for (int k=1; k<=min(len-i, len-j); k++) {
                    if (k == 1) {
                        dpTable[i][j][k] = (s1[i] == s2[j]);
                    } else {
                        for (int splitLen = 1; splitLen < k; splitLen++) {
                            bool ret = (dpTable[i][j][splitLen] && dpTable[i+splitLen][j+splitLen][k-splitLen]) ||
                            (dpTable[i][j+k-splitLen][splitLen] && dpTable[i+splitLen][j][k-splitLen]);
                            if (ret) dpTable[i][j][k] = true;
                        }
                    }
                }
            }
        }
        
        return dpTable[0][0][len];
    }
};