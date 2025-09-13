class Solution {
public:
    int maxFreqSum(string s) {
        vector<int> f(26, 0);
        for (int i = 0; i < s.length(); i++) {
            f[s[i] - 'a']++;
        }
        int num1 = 0, num2 = 0;
        for (int i = 0; i < 26; i++) {
            if (i == 0 || i == 4 || i == 8 || i == 14 || i == 20) {
                num1 = max(num1, f[i]);
            } else {
                num2 = max(num2, f[i]);
            }
        }
        return num1 + num2;
    }
};