class Solution {
public:
    vector<bool> subsequenceSumAfterCapping(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<bool>> dp(k + 1, vector<bool>(n + 1, false));
        for (int i = 0; i <= n; i++) {
            dp[0][i] = true;
        }
        for (int r = 1; r <= k; r++) {
            for (int c = 1; c <= n; c++) {
                dp[r][c] = dp[r][c - 1];
                if (r - nums[c - 1] >= 0) {
                    dp[r][c] = dp[r][c] || dp[r - nums[c - 1]][c-1];
                }
            }
        }
        vector<bool> res;
        int itr = 0;
        for (int x = 1; x <= n; x++) {
            while (itr < n && nums[itr] <= x) {
                itr++;
            }
            if (itr == n) {
                res.push_back(dp[k][n]);
                continue;
            }
            int ct = n - itr;
            bool psb = false;
            for (int i = 0; i <= ct; i++) {
                int l = i * x;
                if (l > k)
                    break;
                int rem = k - l;
                psb = psb || dp[rem][itr];
            }
            res.push_back(psb);
        }
        return res;
    }
};