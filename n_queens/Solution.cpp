class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > ret;
        bool colums[n];
        bool ld2ru[2*n-1];
        bool rd2lu[2*n-1];
        memset(colums, 0, sizeof(colums));
        memset(ld2ru, 0, sizeof(ld2ru));
        memset(rd2lu, 0, sizeof(rd2lu));

        vector<string> sol;
        nQueensHelper(0, colums, ld2ru, rd2lu, n, sol, ret);
        return ret;
    }

    void nQueensHelper(int rowIndex, bool colums[],
                       bool ld2ru[], bool rd2lu[], int n,
                       vector<string> &sol, vector<vector<string> > &solRets) {
        if (rowIndex == n) {
            solRets.push_back(sol);
            return;
        }

        for (int i=0; i<n; i++) {
            if (!colums[i] && !ld2ru[rowIndex+i] && !rd2lu[n-1-i+rowIndex]) {
                colums[i] = ld2ru[rowIndex+i] = rd2lu[n-1-i+rowIndex] = true;
                string posLine(n, '.');
                posLine[i] = 'Q';
                sol.push_back(posLine);
                nQueensHelper(rowIndex+1, colums, ld2ru, rd2lu, n, sol, solRets);
                colums[i] = ld2ru[rowIndex+i] = rd2lu[n-1-i+rowIndex] = false;
                sol.pop_back();
            }
        }
    }
};