#define ll long long
ll mod=1e9+7;
class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<vector<ll>> dp(n + 1, vector<ll>(2));
        dp[0] = {0, 0};
        dp[1] = {1, 1};
        for (int i = 2; i <= n; i++) {
            int x = max(0, i - delay), y = max(0, i - forget);
            dp[i][0] = 0;
            for (int j = y + 1; j <= x; j++) {
                dp[i][0] = (dp[i][0]+dp[j][0])%mod;
            }
            dp[i][1] = (dp[i - 1][1] - dp[y][0] + dp[i][0])%mod;
        }
        if(dp[n][1]<0) return dp[n][1]+mod;
        return dp[n][1];
    }
};