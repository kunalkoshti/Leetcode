#define  ll long long
ll mod = 1e9 + 7;
class Solution {
public:
    int countStableSubsequences(vector<int>& nums) {
        int n = nums.size();
        vector<vector<ll>> dp(n, vector<ll>(4, 0));
        for (int i = 0; i < n; i++) {
            nums[i] = nums[i] % 2;
        }
        if (nums[0] == 0)
            dp[0][0] = 1;
        else
            dp[0][2] = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] == 0) {
                dp[i][0] =
                    (1 + (dp[i - 1][0] + dp[i - 1][2]) % mod + dp[i - 1][3]) %
                    mod;
                dp[i][1] = (dp[i - 1][0] + dp[i - 1][1]) % mod;
                dp[i][2] = dp[i - 1][2];
                dp[i][3] = dp[i - 1][3];
            } else {
                dp[i][0] = dp[i - 1][0];
                dp[i][1] = dp[i - 1][1];
                dp[i][2] =
                    ((dp[i - 1][1] + dp[i - 1][2]) % mod + dp[i - 1][0] + 1) %
                    mod;
                dp[i][3] = (dp[i - 1][2] + dp[i - 1][3]) % mod;
            }
        }
        int res = ((dp[n - 1][0] + dp[n - 1][1]) % mod +
                   (dp[n - 1][2] + dp[n - 1][3]) % mod) %
                  mod;

        return res;
    }
};