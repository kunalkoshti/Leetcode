#define ll long long 
class Solution {
public:
    int best_diff = INT_MAX;
    vector<int> res;
    int n, k;
    void dfs(vector<int>& divs, vector<int>& picked, int idx, int ct,
             int prod) {
        if (ct == k && prod == n) {
            if (picked[k - 1] - picked[0] < best_diff) {
                best_diff = picked[k - 1] - picked[0];
                res = picked;
            }
        }
        if (ct == k || idx >= divs.size())
            return;
        for (int i = idx; i < divs.size(); i++) {
            if((ll) prod* (ll) divs[i] > (ll) n) break;
            picked.push_back(divs[i]);
            dfs(divs, picked, i, ct + 1, prod * divs[i]);
            picked.pop_back();
        }
    }
    vector<int> minDifference(int n_, int k_) {
        vector<int> divs;
        n = n_, k = k_;
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                divs.push_back(i);
                divs.push_back(n / i);
            }
        }
        sort(divs.begin(), divs.end());
        vector<int> picked = {};
        dfs(divs, picked, 0, 0, 1);
        return res;
    }
};