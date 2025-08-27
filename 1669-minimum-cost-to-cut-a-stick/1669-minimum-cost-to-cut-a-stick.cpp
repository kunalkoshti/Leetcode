class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        int k = cuts.size();
        sort(cuts.begin(),cuts.end());
        vector<vector<int>> dp(k, vector<int>(k, INT_MAX));
        for (int r = 0; r < k - 1; r++) {
            dp[r][r] = 0;
            dp[r][r + 1] = 0;
        }
        for (int sz = 2; sz < k; sz++) {
            for (int r = 0; r < k - sz; r++) {
                int c = r + sz;
                for (int t = r + 1; t < c; t++) {
                    dp[r][c] =
                        min(dp[r][c], dp[r][t] + dp[t][c] + cuts[c] - cuts[r]);
                }
            }
        }
        return dp[0][k - 1];
    }
};