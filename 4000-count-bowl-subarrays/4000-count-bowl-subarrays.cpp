#define ll long long
class Solution {
public:
    long long bowlSubarrays(vector<int>& nums) {
        int n = nums.size();
        ll res = 0;
        stack<int> s;
        if (nums[1] > nums[0])
            s.push(nums[1]);
        else {
            s.push(nums[0]);
            s.push(nums[1]);
        }
        for (int i = 2; i < n; i++) {
            if (nums[i] > s.top()) {
                ll ct = 0;
                while (!s.empty() && s.top() < nums[i]) {
                    ct++;
                    s.pop();
                }
                if(s.empty()) ct--;
                res += ct;
            }
            s.push(nums[i]);
        }
        return res;
    }
};