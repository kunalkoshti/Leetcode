class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int minv = INT_MAX, maxv = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            minv = min(minv, nums[i]);
            maxv = max(maxv, nums[i]);
        }
        long long res = (long long)(maxv - minv) * k;
        return res;
    }
};