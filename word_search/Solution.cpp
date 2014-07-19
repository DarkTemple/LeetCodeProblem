class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        if (board.empty()) return false;
        int m = (int)board.size();
        int n = (int)board[0].size();
        vector<vector<bool> > visited(m, vector<bool>(n, false));
        for (int i=0; i<board.size(); i++) {
            for (int j=0; j<board[0].size(); j++) {
                if (dfs(board, visited, i, j, word, 0)) return true;
            }
        }
        
        return false;
    }
    
    bool dfs(vector<vector<char> > &board, vector<vector<bool> > &visited, int row, int column, string &word, int index) {
        if (row < 0 || row >= board.size() || column < 0 || column >= board[0].size()) return false;
        if (visited[row][column]) return false;
        if (board[row][column] == word[index]) {
            if (index == word.length()-1) return true;
            visited[row][column] = true;
            bool ret = dfs(board, visited, row-1, column, word, index+1) ||
                       dfs(board, visited, row, column-1, word, index+1) ||
                       dfs(board, visited, row+1, column, word, index+1) ||
                       dfs(board, visited, row, column+1, word, index+1);
            visited[row][column] = false;
            return ret;
        }
        
        return false;
    }
};