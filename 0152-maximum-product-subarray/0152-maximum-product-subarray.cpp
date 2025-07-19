class Solution {
    int n;

public:
    int get_max_ele(vector<int>& nums) {
        int max_ele = -11;
        for (int i = 0; i < n; i++) {
            max_ele = max(max_ele, nums[i]);
        }
        return max_ele;
    }
    int maxProduct(vector<int>& nums) {
        n = nums.size();
        int me = get_max_ele(nums);
        if (me < 0 && n == 1)
            return me;
        int res = -1;
        int mp = 1, mn = 1;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                mp = mn = 1;
                res = max(res, 0);
                continue;
            } else if (nums[i] > 0) {
                mp = mp * nums[i];
                mn = min(1, mn * nums[i]);
                res = max(res, mp);
            } else {
                int t=mp;
                if (mn * nums[i] < 0) {
                    mp = 1;
                } else {
                    mp = mn * nums[i];
                    res = max(res, mp);
                }
                mn = t * nums[i];
            }
            cout<<res<<endl;
        }
        return res;
    }
};