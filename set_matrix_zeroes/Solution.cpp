class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int m = (int)matrix.size();
        int n = (int)matrix[0].size();
        bool isRowClear = false, isColClear = false;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (matrix[i][j] == 0) {
                    if (i == 0) isRowClear = true;
                    matrix[0][j] = 0;
                    if (j == 0) isColClear = true;
                    matrix[i][0] = 0;
                }
            }
        }
        
        for (int i=1; i<m; i++) {
            if (matrix[i][0] == 0) {
                for (int j=0; j<n; j++) {
                    matrix[i][j] = 0;
                }
            }
        }
        
        for (int j=1; j<n; j++) {
            if (matrix[0][j] == 0) {
                for (int i=0; i<m; i++) {
                    matrix[i][j] = 0;
                }
            }
        }
        
        if (isRowClear) {
            for (int j=0; j<n; j++) matrix[0][j] = 0;
        }
        
        if (isColClear) {
            for (int i=0; i<m; i++) matrix[i][0] = 0;
        }
    }
};