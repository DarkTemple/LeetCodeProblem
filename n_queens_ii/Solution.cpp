class Solution {
public:
    int totalNQueens(int n) {
        bool ld2ru[2*n-1];
        bool rd2lu[2*n-1];
        bool column[n];
        int totalCount = 0;
        memset(ld2ru, 0, sizeof(bool)*(2*n-1));
        memset(rd2lu, 0, sizeof(bool)*(2*n-1));
        memset(column, 0, sizeof(bool)*n);
        NQueensHelper(0, n, ld2ru, rd2lu, column, totalCount);
        return totalCount;
    }
    
    void NQueensHelper(int row, int n, bool *ld2ru, bool *rd2lu, bool *column, int &totalCount) {
        if (row == n) {
            totalCount++;
            return ;
        }
        
        for (int col=0; col<n; col++) {
            if (!column[col] && !ld2ru[row+col] && !rd2lu[n-1-col+row]) {
                column[col] = ld2ru[row+col] = rd2lu[n-1-col+row] = true;
                NQueensHelper(row+1, n, ld2ru, rd2lu, column, totalCount);
                column[col] = ld2ru[row+col] = rd2lu[n-1-col+row] = false;
            }
        }
    }
};