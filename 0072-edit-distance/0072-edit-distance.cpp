class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.length(), n2 = word2.length();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
        for (int r = 1; r <= n1; r++) {
            dp[r][0] = r;
        }
        for (int c = 1; c <= n2; c++) {
            dp[0][c] = c;
        }
        for (int r = 1; r <= n1; r++) {
            for (int c = 1; c <= n2; c++) {
                dp[r][c] = INT_MAX;
                if (word1[r-1] == word2[c-1]) {
                    dp[r][c] = dp[r - 1][c - 1];
                }

                dp[r][c] = min(
                    dp[r][c],
                    min({dp[r][c - 1], dp[r - 1][c], dp[r - 1][c - 1]}) + 1);
            }
        }
        return dp[n1][n2];
    }
};