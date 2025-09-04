class Solution {
public:
    vector<vector<char>> res;
    bool check(vector<vector<char>>& board, int x, int y) {
        char num = board[x][y];
        for (int i = 0; i < 9; i++) {
            if ((i != y && board[x][i] == num) ||
                (i != x && board[i][y] == num))
                return false;
        }
        int sr = (x / 3) * 3, sc = (y / 3) * 3;
        int ct = 0;
        for (int r = 0; r < 3; r++) {
            for (int c = 0; c < 3; c++) {
                if (board[sr + r][sc + c] == num)
                    ct++;
            }
        }
        return ct == 1;
    }
    void dfs(vector<vector<char>>& board, vector<pair<int, int>>& empty,
             int idx) {
        if (idx == empty.size()) {
            res = board;
            return;
        }
        int x = empty[idx].first, y = empty[idx].second;
        for (int i = 1; i <= 9; i++) {
            board[x][y] = i + '0';
            if (check(board, x, y)) {
                dfs(board, empty, idx + 1);
            }
            board[x][y] = '.';
        }
    }
    void solveSudoku(vector<vector<char>>& board) {
        vector<pair<int, int>> empty;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    empty.push_back({i, j});
                }
            }
        }
        dfs(board, empty, 0);
        board = res;
    }
};