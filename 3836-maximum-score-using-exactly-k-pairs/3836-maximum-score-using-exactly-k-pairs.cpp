#define ll long long

class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        int m = nums2.size();
        
        // Initialize with a very small value to handle negative products
        const ll INF = 1e17; 
        
        // dp[i][j][t] = max score using first i of nums1, first j of nums2, and t pairs
        // Using a 3D vector: [n+1][m+1][k+1]
        vector<vector<vector<ll>>> dp(n + 1, vector<vector<ll>>(m + 1, vector<ll>(k + 1, -INF)));

        // Base case: If we need 0 pairs, the score is always 0
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                dp[i][j][0] = 0;
            }
        }

        for (int t = 1; t <= k; t++) {
            for (int i = t; i <= n; i++) {
                for (int j = t; j <= m; j++) {
                    // Option 1: Skip nums1[i-1]
                    dp[i][j][t] = max(dp[i][j][t], dp[i-1][j][t]);
                    
                    // Option 2: Skip nums2[j-1]
                    dp[i][j][t] = max(dp[i][j][t], dp[i][j-1][t]);
                    
                    // Option 3: Pair up nums1[i-1] and nums2[j-1]
                    // (We use i-1 and j-1 because the input arrays are 0-indexed)
                    if (dp[i-1][j-1][t-1] != -INF) {
                        ll current_prod = (ll)nums1[i-1] * nums2[j-1];
                        dp[i][j][t] = max(dp[i][j][t], dp[i-1][j-1][t-1] + current_prod);
                    }
                }
            }
        }

        return dp[n][m][k];
    }
};



