/*
 * dp[i][j] = dp[i][j-1] + (T[i] == S[j] ? dp[i-1][j-1] : 0);
 */
class Solution
{
public:
    int numDistinct(string S, string T) {
        int dpTable[T.length()+1][S.length()+1];
        memset(dpTable, 0, sizeof(dpTable));
        for (int i=0; i<S.length(); i++) {
            dpTable[0][i] = 1;
        }
        
        for (int i=1; i<=T.length(); i++) {
            for (int j=1; j<=S.length(); j++) {
                dpTable[i][j] = dpTable[i][j-1] + (T[i-1] == S[j-1] ? dpTable[i-1][j-1] : 0);
            }
        }
        
        return dpTable[T.length()][S.length()];
    }
};