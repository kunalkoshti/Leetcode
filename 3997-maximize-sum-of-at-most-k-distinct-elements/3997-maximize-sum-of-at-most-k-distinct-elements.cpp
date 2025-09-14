class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for (int i = 0; i < nums.size(); i++) {
            pq.push(nums[i]);
        }
        vector<int> res={};
        int prev = -1;
        for (int i = 0; i < k && !pq.empty(); i++) {
            while (!pq.empty() && pq.top() == prev) {
                pq.pop();
            }
            if (pq.empty())
                break;
            res.push_back(pq.top());
            prev = pq.top();
            pq.pop();
        }
        return res;
    }
};