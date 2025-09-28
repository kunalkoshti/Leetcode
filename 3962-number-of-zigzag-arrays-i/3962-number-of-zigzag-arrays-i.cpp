int mod = 1e9 + 7;
class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        if (l == r)
            return 0;
        int size = r - l + 1;
        vector<vector<pair<int, int>>> dp(n,
                                          vector<pair<int, int>>(size, {0, 0}));
        for (int c = 0; c < size; c++) {
            dp[0][c] = {c+1,c+1};
        }

        for (int r = 1; r < n; r++) {
            for (int c = 0; c < size; c++) {
                int n1=0, n2=0;
                if (c - 1 >= 0)
                    n1 = ((long long)dp[r - 1][c - 1].second +
                          dp[r][c - 1].first) %
                         mod;
                if (n1 < 0)
                    n1 += mod;
                dp[r][c].first = n1;
                n2 = ((long long)dp[r - 1][size - 1].first -
                      dp[r - 1][c].first) %
                     mod;
                if (c - 1 >= 0)
                    n2 = ((long long)dp[r][c - 1].second + n2) %
                         mod;
                if (n2 < 0)
                    n2 += mod;
                dp[r][c].second = n2;
            }
        }
        int res = ((long long)dp[n - 1][size - 1].first +
                   dp[n - 1][size - 1].second) %
                  mod;
        if (res < 0)
            res += mod;
        return res;
    }
};