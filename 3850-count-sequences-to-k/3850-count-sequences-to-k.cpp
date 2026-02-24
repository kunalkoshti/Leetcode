class Solution {
public:
    vector<vector<int>> factors;
    void initialize_factors() {
        factors.resize(7);
        factors[1] = {0, 0, 0};
        factors[2] = {1, 0, 0};
        factors[3] = {0, 1, 0};
        factors[4] = {2, 0, 0};
        factors[5] = {0, 0, 1};
        factors[6] = {1, 1, 0};
    }

    void gen(vector<int>& nums, int l, int r, map<vector<int>, int>& dp) {
        queue<vector<int>> q;
        q.push({0, 0, 0});
        for (int i = l; i <= r; i++) {
            int sz = q.size();
            vector<int> fact = factors[nums[i]];

            for (int j = 0; j < sz; j++) {
                vector<int> curr = q.front();
                q.pop();

                q.push(curr);
                q.push(
                    {curr[0] + fact[0], curr[1] + fact[1], curr[2] + fact[2]});
                q.push(
                    {curr[0] - fact[0], curr[1] - fact[1], curr[2] - fact[2]});
            }
        }
        while (!q.empty()) {
            auto curr = q.front();
            q.pop();
            if (dp.find(curr) == dp.end())
                dp[curr] = 1;
            else
                dp[curr]++;
        }
        return;
    }
    bool factorize(long long k, vector<int>& target) {
        while (k % 2 == 0) {
            k /= 2;
            target[0]++;
        }
        while (k % 3 == 0) {
            k /= 3;
            target[1]++;
        }
        while (k % 5 == 0) {
            k /= 5;
            target[2]++;
        }
        if (k != 1)
            return false;
        return true;
    }

    int countSequences(vector<int>& nums, long long k) {
        vector<int> target(3, 0);
        if (!factorize(k, target))
            return 0;
        initialize_factors();
        int n = nums.size();
        int mid = n / 2;
        map<vector<int>, int> L;
        map<vector<int>, int> R;
        gen(nums, 0, mid, L);
        gen(nums, mid + 1, n - 1, R);
        int res = 0;
        for (auto& p : L) {
            auto curr = p.first;
            int ta = target[0] - curr[0], tb = target[1] - curr[1],
                tc = target[2] - curr[2];
            if (R.find({ta, tb, tc}) == R.end())
                continue;
            res += (p.second * R[{ta, tb, tc}]);
        }
        return res;
    }
};