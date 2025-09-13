#define ll long long
class Solution {
public:
    vector<array<int, 6>> st;
    vector<int> popcount;
    int ct_set_bits(ll n) {
        int cnt = 0;
        while (n) {
            n &= (n - 1); // drop the lowest set bit
            cnt++;
        }
        return cnt;
    }
    void calc_pop(vector<int>& popcount) {
        for (int i = 2; i < popcount.size(); i++) {
            int bits = ct_set_bits(i);
            popcount[i] = 1 + popcount[bits];
        }
    }

    void create_tree(int l, int r, int idx, vector<long long>& nums) {
        if (l == r) {
            int dep = 1 + popcount[ct_set_bits(nums[l])];
            if (nums[l] == 1)
                dep = 0;
            st[idx][dep] = 1;
            return;
        }
        int mid = (l + r) / 2;
        create_tree(l, mid, 2 * idx, nums);
        create_tree(mid + 1, r, 2 * idx + 1, nums);
        for (int i = 0; i < 6; i++) {
            st[idx][i] = st[2 * idx][i] + st[2 * idx + 1][i];
        }
        return;
    }
    pair<int, int> update_tree(int l, int r, int idx, ll n, ll val,
                               vector<long long>& nums) {

        if (l == r && r == n) {
            int prev_dep = -1;
            for (int i = 0; i < 6; i++) {
                if (st[idx][i] == 1) {
                    prev_dep = i;
                    st[idx][i] = 0;
                }
            }
            nums[l] = val;
            int dep = 1 + popcount[ct_set_bits(val)];
            if (val == 1)
                dep = 0;
            st[idx][dep] = 1;
            return {prev_dep, dep};
        }
        int mid = (l + r) / 2;
        pair<int, int> p;
        if (n >= l && n <= mid) {
            p = update_tree(l, mid, 2 * idx, n, val, nums);
        } else {
            p = update_tree(mid + 1, r, 2 * idx + 1, n, val, nums);
        }
        st[idx][p.first]--;
        st[idx][p.second]++;
        return p;
    }
    int find(int l, int r, int idx, ll p, ll q, ll dep) {
        if (p > r || q < l)
            return 0;
        if (l == p && r == q) {
            return st[idx][dep];
        }
        int mid = (l + r) / 2;
        if (q <= mid) {
            return find(l, mid, 2 * idx, p, q, dep);
        }
        if (p >= mid + 1) {
            return find(mid + 1, r, 2 * idx + 1, p, q, dep);
        }
        return find(l, mid, 2 * idx, p, mid, dep) +
               find(mid + 1, r, 2 * idx + 1, mid + 1, q, dep);
    }

    vector<int> popcountDepth(vector<long long>& nums,
                              vector<vector<long long>>& queries) {
        st.resize(4*nums.size());
        popcount.resize(65, 0);
        calc_pop(popcount);
        // max_depth = 4
        create_tree(0, nums.size() - 1, 1, nums);
        vector<int> res;
        for (int i = 0; i < queries.size(); i++) {
            if (queries[i][0] == 1) {
                res.push_back(find(0, nums.size() - 1, 1, queries[i][1],
                                   queries[i][2], queries[i][3]));
            } else {
                update_tree(0, nums.size() - 1, 1, queries[i][1], queries[i][2],
                            nums);
            }
        }

        return res;
    }
};