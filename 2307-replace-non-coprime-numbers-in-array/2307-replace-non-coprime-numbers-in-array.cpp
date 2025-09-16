#define ll long long
class Solution {
public:
    int gcd(int x1, int x2) {
        if (x1 < x2) {
            int t = x1;
            x1 = x2;
            x2 = t;
        }
        if (x1 % x2 == 0)
            return x2;
        return gcd(x2, x1 % x2);
    }
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<int> s;
        s.push(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            ll curr = nums[i];
            while (!s.empty()) {
                int g = gcd(s.top(), curr);
                if (g == 1)
                    break;
                else {
                    curr = (curr * s.top()) / g;
                    s.pop();
                }
            }
            s.push(curr);
        }
        vector<int> res;
        while (!s.empty()) {
            res.push_back(s.top());
            s.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};