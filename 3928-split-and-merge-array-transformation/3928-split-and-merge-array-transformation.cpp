class Solution {
public:
    int minSplitMerge(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        if (nums1 == nums2)
            return 0;
        set<vector<int>> visited;
        queue<pair<vector<int>, int>> q;
        q.push({nums1, 0});
        visited.insert(nums1);
        while (!q.empty()) {
            vector<int> nums = q.front().first;
            int ops = q.front().second;
            q.pop();
            for (int l = 0; l < n; l++) {
                for (int r = l; r < n; r++) {
                    vector<int> sub(nums.begin() + l, nums.begin() + r + 1);
                    vector<int> rem;
                    if (l - 1 >= 0)
                        rem.insert(rem.end(), nums.begin(), nums.begin() + l);
                    if (r + 1 < n)
                        rem.insert(rem.end(), nums.begin() + r + 1, nums.end());
                    for (int i = 0; i <= rem.size(); i++) {
                        vector<int> newarr = rem;
                        newarr.insert(newarr.begin() + i, sub.begin(),
                                      sub.end());
                        if (visited.count(newarr))
                            continue;
                        if (newarr == nums2)
                            return ops + 1;
                        visited.insert(newarr);
                        q.push({newarr, ops + 1});
                    }
                }
            }
        }
        return -1;
    }
};