class Solution {
public:
    vector<int> prefix_funct_opt(string s) {
        vector<int> res(s.length(), 0);
        for (int i = 1; i < s.length(); i++) {
            int j = res[i - 1];
            while (j > 0 && s[j] != s[i]) {
                j = res[j - 1];
            }
            if (s[j] == s[i])
                j++;
            res[i] = j;
        }
        return res;
    }

    int strStr(string haystack, string needle) {
        string t = needle + "#" + haystack;
        int n = needle.length();
        int m = haystack.length();
        vector<int> pi = prefix_funct_opt(t);
        for (int i = 2 * n; i < t.length(); i++) {
            if (pi[i] == n)
                return i - 2 * n;
        }
        return -1;
    }
};