class Solution {
public:
    void changeState(vector<vector<char> > &board, int i, int j) {
        int height = board.size();
        int width = board[0].size();
        queue<pair<int, int> > q;
        q.push(make_pair(i, j));
        while (!q.empty()) {
            pair<int, int>pos = q.front();
            i = pos.first;
            j = pos.second;
            q.pop();
            if (i < 0 || i == height ||
                j < 0 || j == width)
                continue;

            char c = board[i][j];
            if (c == 'O') {
                board[i][j] = 'T';
                q.push(make_pair(i-1, j));
                q.push(make_pair(i+1, j));
                q.push(make_pair(i, j-1));
                q.push(make_pair(i, j+1));
            }
        }
    }

    void solve(vector<vector<char> > &board) {
        if (board.empty()) return;
        int height = board.size();
        int width = board[0].size();

        // up
        for (int j=0; j<width; j++) changeState(board, 0, j);
        // left
        for (int i=0; i<height; i++) changeState(board, i, 0);
        // down
        for (int j=0; j<width; j++) changeState(board, height-1, j);
        // right
        for (int i=0; i<height; i++) changeState(board, i, width-1);


        for (int i=0; i<height; i++) {
            for (int j=0; j<width; j++) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == 'T') board[i][j] = 'O';
            }
        }
    }
};