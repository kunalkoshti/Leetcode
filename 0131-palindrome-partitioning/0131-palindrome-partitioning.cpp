class Solution {
public:
    bool is_pal(string& s, int i, int j) {
        int l = i, r = j;
        while (l < r) {
            if (s[l] != s[r])
                return false;
            l++, r--;
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        int n = s.length();
        vector<vector<vector<string>>> dp(n + 1);
        dp[0] = {{}};
        for (int i = 0; i < n; i++) {
            vector<vector<string>> ans = {};
            for (int j = 0; j <= i; j++) {
                if (is_pal(s, j, i)) {
                    string t = s.substr(j, i - j + 1);
                    for (int l = 0; l < dp[j].size(); l++) {
                        vector<string> temp = dp[j][l];
                        temp.push_back(t);
                        ans.push_back(temp);
                    }
                }
            }
            dp[i + 1] = ans;
        }
        return dp[n];
    }
};