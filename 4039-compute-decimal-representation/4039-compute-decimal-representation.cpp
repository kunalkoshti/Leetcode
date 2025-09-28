class Solution {
public:
    vector<int> decimalRepresentation(int n) {
        vector<int> res;
        int mul = 1;
        while (n != 0) {
            if (n % 10 != 0) {
                res.push_back((n % 10) * mul);
            }
            n /= 10;
            if(n>0)  mul *= 10;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};