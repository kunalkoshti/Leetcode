class Solution {
    int res = 0;

public:
    void mergeSort(vector<int>& nums, int l, int r) {
        if (l == r)
            return;
        int mid = (l + r) / 2;
        mergeSort(nums, l, mid);
        mergeSort(nums, mid + 1, r);
        int i = l, j = mid + 1, ptr = mid + 1;
        vector<int> temp;
        while (i <= mid && j <= r) {
            if (nums[j] <= nums[i]) {
                temp.push_back(nums[j]);
                j++;
            } else {
                int val = ptr - mid - 1;
                while (ptr <= r && (long long)nums[i] > 2LL * nums[ptr]) {
                    ptr++, val++;
                }
                temp.push_back(nums[i]);
                i++;
                res += val;
            }
        }
        while (j <= r) {
            temp.push_back(nums[j]);
            j++;
        }
        while (i <= mid) {
            int val = ptr - mid - 1;
            while (ptr <= r && (long long)nums[i] > 2LL * nums[ptr]) {
                ptr++, val++;
            }
            temp.push_back(nums[i]);
            i++;
            res += val;
        }
        cout << res << " ";
        for (int k = l; k <= r; k++) {
            nums[k] = temp[k - l];
        }
    }
    int reversePairs(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return res;
    }
};