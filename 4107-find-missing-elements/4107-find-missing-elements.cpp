class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<bool> exist(101, false);
        int small = INT_MAX, large = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            exist[nums[i]] = true;
            small = min(small, nums[i]);
            large = max(large, nums[i]);
        }
        vector<int> res;
        for (int i = small + 1; i < large; i++) {
            if (!exist[i]) {
                res.push_back(i);
            }
        }
        return res;
    }
};