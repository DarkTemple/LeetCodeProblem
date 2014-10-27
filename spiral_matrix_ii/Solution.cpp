class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > ret;
        for (int i=0; i<n; i++) {
            vector<int> row(n, 0);
            ret.push_back(row);
        }
        
        int up = 0, right = n - 1, down = n - 1, left = 0;
        int number = 0;
        int i = 0, j = 0;
        while (up <= down && left <= right) {
            // from left to left
            while (j <= right) {
                ret[i][j++] = ++number;
            }
            
            j = right;
            i = ++up;
            
            // from up to down
            while (i <= down) {
                ret[i++][j] = ++number;
            }
            
            i = down;
            j = --right;
            
            
            // from right to left
            while (j >= left) {
                ret[i][j--] = ++number;
            }
            
            j = left;
            i = --down;
            
            // from down to up
            while (i >= up) {
                ret[i--][j] = ++number;
            }
            
            i = up;
            j = ++left;
        }
        
        return ret;
    }
};