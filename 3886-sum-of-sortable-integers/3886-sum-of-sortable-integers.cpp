class Solution {
public:
    bool is_cyclical(vector<int>& nums,int l,int r){
        bool fl=false;
        for(int i=l+1;i<=r;i++){
            if(nums[i]<nums[i-1]){
                if(fl || nums[i]>nums[l] || nums[r]>nums[l]) return false;
                fl=true;
            }
        }
        return true;
    } 
    bool is_sortable(vector<int>& nums, int k) {
        int n = nums.size();
        pair<int, int> prev = {INT_MAX, INT_MIN};
        for (int s = 0; s < n; s += k) {
            if (!is_cyclical(nums, s, s + k - 1))
                return false;
            pair<int, int> curr = {INT_MAX, INT_MIN};
            for (int i = s; i < s + k; i++) {
                curr.first = min(curr.first, nums[i]);
                curr.second = max(curr.second, nums[i]);
            }
            if (prev.second > curr.first)
                return false;
            prev = curr;
        }
        return true;
    }
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        for (int k = 1; (k * k) <= n; k++) {
            if (n % k != 0)
                continue;
            if (is_sortable(nums, k))
               { cout<<k<<" ";
                res += k;}
            if ((k * k) == n)
                continue;
            if (is_sortable(nums, n / k))
                { cout<<(n/k)<<" ";
                res += (n/k);}
        }
        return res;
    }
};