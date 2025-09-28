class Solution {
public:
    long long splitArray(vector<int>& nums) {
        int idx = -1;
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            if ((nums[i] >= nums[i - 1]) && idx != -1)
                return -1;
            else if (nums[i] <= nums[i - 1] && idx == -1)
                idx = i - 1;
        }
        bool fl = false;
        if (idx == -1) {
            idx = n - 2;
            fl = true;
        }
        long long right = 0, left = 0;
        for (int i = 0; i < n; i++) {
            if (i <= idx)
                left += (long long)nums[i];
            else
                right += (long long)nums[i];
        }
        if ((idx + 1 < n && nums[idx] == nums[idx + 1]) || idx == 0 ||
            (idx == n - 2 && fl))
            return abs(right - left);
        long long res1 = abs(right - left),
                  res2 = abs(right - left + 2 * (long long)nums[idx]);
        if (res1 <= res2)
            return res1;
        return res2;
    }
};