class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int> dc;
        for (int r = 0; r < bank.size(); r++) {
            int ct = 0;
            for (int c = 0; c < bank[r].size(); c++) {
                if (bank[r][c] == '1')
                    ct++;
            }
            if (ct > 0)
                dc.push_back(ct);
        }
        if (dc.size() < 2)
            return 0;
        int res = 0;
        for (int i = 1; i < dc.size(); i++) {
            res += dc[i] * dc[i - 1];
        }
        return res;
    }
};