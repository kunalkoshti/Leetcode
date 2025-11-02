#define ll long long
class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        ll neg = -1e5, pst = 1e5;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        ll p1 = (ll)nums[n - 1] * nums[n - 2], p2 = (ll)nums[0] * nums[1],
           p3 = (ll)nums[0] * nums[n - 1];
        ll res = p1 * pst;
        if (p2 * pst > res)
            res = p2 * pst;
        if (p3 * neg > res)
            res = p3 * neg;
        return res;
    }
};