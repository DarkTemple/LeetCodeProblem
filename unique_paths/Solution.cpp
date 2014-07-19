class Solution {
public:
    int uniquePaths(int m, int n) {
        int dpTable[n];
        dpTable[0] = 1;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (i == 0 && j == 0) continue;
                dpTable[j] = (i > 0 ? dpTable[j] : 0) + (j > 0 ? dpTable[j-1] : 0);
            }
        }
        
        return dpTable[n-1];
    }
};