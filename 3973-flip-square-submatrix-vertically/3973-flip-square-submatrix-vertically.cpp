class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x,
                                         int y, int k) {
        for (int c = y; c < y + k; c++) {
            int t = x, b = x + k - 1;
            while (t < b) {
                int temp = grid[t][c];
                grid[t][c] = grid[b][c];
                grid[b][c] = temp;
                t++;
                b--;
            }
        }
        return grid;
    }
};