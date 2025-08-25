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

    vector<int> z_funct(string s) {
        int n = s.length();
        int l = 0, r = 0;
        vector<int> z(n, 0);
        for (int i = 1; i < n; i++) {
            if (i < r)
                z[i] = min(r - i, z[i - l]);
            for (int j = z[i]; j < n - i; j++) {
                if (s[j] == s[i + j])
                    z[i]++;
                else
                    break;
            }
            if (i + z[i] > r) {
                l = i, r = i + z[i];
            }
        }
        return z;
    }

    int strStr(string haystack, string needle) {
        string t = needle + "#" + haystack;
        int n = needle.length();
        int m = haystack.length();
        //vector<int> pi = prefix_funct_opt(t);
        vector<int> z = z_funct(t);
        for (int i = n+1; i < t.length(); i++) {
            if (z[i] == n)
                return i - (n+1);
        }
        return -1;
    }
};