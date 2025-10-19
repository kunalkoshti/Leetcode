class Solution {
public:
    string create_dec(unordered_map<char, int>& mp) {
        string s = "";
        for (int l = 25; l >= 0; l--) {
            if (mp.find('a' + l) != mp.end() && mp['a' + l] > 0) {
                for (int k = 0; k < mp['a' + l]; k++) {
                    s += ('a' + l);
                }
            }
        }
        return s;
    }
    int isPossible(string& t, int idx, unordered_map<char, int>& mp) {
        if (idx == t.length())
            return 2;
        string s = create_dec(mp);

        for (int i = idx; i < t.length(); i++) {
            if (t[i] - 'a' < s[i - idx] - 'a')
                return 1;
            else if (t[i] - 'a' > s[i - idx] - 'a')
                return 0;
        }
        return 2;
    }

    string lexGreaterPermutation(string s, string target) {
        unordered_map<char, int> mp;
        for (int i = 0; i < s.length(); i++) {
            if (mp.find(s[i]) == mp.end())
                mp[s[i]] = 1;
            else
                mp[s[i]]++;
        }
        string res = "";
        for (int i = 0; i < s.length(); i++) {
            char c = target[i];
            if (mp.find(c) != mp.end() && mp[c] > 0) {
                mp[c]--;
                if (isPossible(target, i + 1, mp) == 1) {
                    res += c;
                    continue;
                }
                mp[c]++;
            }
            char add = ' ';
            for (int j = c - 'a' + 1; j < 26; j++) {
                char curr = 'a' + j;
                if (mp.find(curr) == mp.end() || mp[curr] == 0)
                    continue;

                add = curr;
                mp[curr]--;
                break;
            }
            if (add == ' ')
                return "";
            string suff = create_dec(mp);
            reverse(suff.begin(), suff.end());
            res = res + add + suff;
            return res;
        }
        return res;
    }
};