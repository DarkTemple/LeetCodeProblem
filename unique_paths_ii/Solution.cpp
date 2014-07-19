class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m = (int)obstacleGrid.size();
        int n = (int)obstacleGrid[0].size();
        int dpTable[n];
        dpTable[0] = obstacleGrid[0][0] == 1 ? 0 : 1;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (i == 0 && j == 0) continue;
                dpTable[j] = obstacleGrid[i][j] == 1 ? 0 : ((i > 0 ? dpTable[j] : 0) + (j > 0 ? dpTable[j-1] : 0));
            }
        }
        
        return dpTable[n-1];
    }
};