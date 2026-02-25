class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int> curr = {0, 0, 0};
        for (int i = 0; i < triplets.size(); i++) {
            if (triplets[i][0] > target[0] || triplets[i][1] > target[1] ||
                triplets[i][2] > target[2])
                continue;
            curr[0] = max(curr[0], triplets[i][0]);
            curr[1] = max(curr[1], triplets[i][1]);
            curr[2] = max(curr[2], triplets[i][2]);
        }
        return (curr[0] == target[0] && curr[1] == target[1] && curr[2] ==
                    target[2]);
    }
};