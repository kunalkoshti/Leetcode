class Solution {
public:
    bool common(vector<int>& v1, vector<int>& v2) {
        int l = 0, r = 0;
        while (l < v1.size() && r < v2.size()) {
            if (v1[l] == v2[r])
                return true;
            else if (v1[l] < v2[r])
                l++;
            else
                r++;
        }
        return false;
    }
    bool contain(vector<int>& v, int n) {
        auto itr = lower_bound(v.begin(), v.end(), n);
        if (itr != v.end() && *itr == n)
            return true;
        return false;
    }
    int minimumTeachings(int n, vector<vector<int>>& languages,
                         vector<vector<int>>& friendships) {
        int res = INT_MAX;
        int m = languages.size();
        for (int i = 0; i < m; i++) {
            sort(languages[i].begin(), languages[i].end());
        }

        for (int i = 1; i <= n; i++) {
            int ans = 0;
            vector<int> changed(m + 1, false);
            for (int j = 0; j < friendships.size(); j++) {
                int x = friendships[j][0], y = friendships[j][1];
                if (common(languages[x - 1], languages[y - 1]))
                    continue;
                if (!changed[x] && !contain(languages[x - 1], i)) {
                    ans++;
                    changed[x] = true;
                }
                if (!changed[y] && !contain(languages[y - 1], i)) {
                    ans++;
                    changed[y] = true;
                }
            }
            res = min(res, ans);
        }
        return res;
    }
};