class Solution {
public:
    int getMatricIdxValue(vector<vector<int> > &matrix, int index) {
        int colNum = (int)matrix[0].size();
        int rowIdx = index/colNum;
        int colIdx = index%colNum;
        return matrix[rowIdx][colIdx];
    }
    
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int rowNum = (int)matrix.size();
        int colNum = (int)matrix[0].size();
        if (rowNum == 0 || colNum == 0) {
            return false;
        }
        
        int start = 0;
        int end = rowNum * colNum - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            int midVal = getMatricIdxValue(matrix, mid);
            if (midVal == target) {
                return true;
            } else if (midVal < target) {
                start++;
            } else {
                end--;
            }
        }
        
        return false;
    }
};