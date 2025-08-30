class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> premax(n);
        vector<int> sufmin(n);
        premax[0] = nums[0];
        sufmin[n - 1] = nums[n - 1];
        for (int i = 1; i < n; i++) {
            premax[i] = max(nums[i], premax[i - 1]);
        }
        for (int i = n - 2; i >= 0; i--) {
            sufmin[i] = min(nums[i], sufmin[i + 1]);
        }
        vector<int> res;
        int l = 0, max_int = INT_MIN;
        for (int i = 0; i < n - 1; i++) {
            max_int = max(max_int, nums[i]);
            if (premax[i] <= sufmin[i + 1]) {
                res.insert(res.end(), i - l + 1, max_int);
                max_int = INT_MIN;
                l = i + 1;
            }
        }
        max_int = max(max_int, nums[n - 1]);
        res.insert(res.end(), n - l, max_int);
        return res;
    }
};