class Solution {
public:
    int count(string& s, int l, int r, bool deleted, int curr) {
        if (l < 0 || r >= s.length()){
            if(deleted || l>=0 || r<s.length()) return 1+curr;
            else return curr;
        }
            
        if (s[l] == s[r])
            return count(s, l - 1, r + 1, deleted, curr + 2);
        if (deleted)
            return 1+curr;
        return max(count(s,l - 1, r, true, curr), count(s,l, r + 1, true, curr));
    }
    int almostPalindromic(string s) {
        int res = 0;
        for (int i = 0; i < s.length(); i++) {
            res = max({res, count(s, i, i + 1, false, 0),
                       count(s, i - 1, i + 1, false, 1)});
        }
        return res;
    }
};