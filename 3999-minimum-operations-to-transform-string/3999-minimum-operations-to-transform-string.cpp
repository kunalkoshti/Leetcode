class Solution {
public:
    int minOperations(string s) {
        unordered_map<char, int> mp;
        for (int i = 0; i < s.length(); i++) {
            if (mp.find(s[i]) == mp.end()) {
                mp[s[i]] = 1;
            } else {
                mp[s[i]]++;
            }
        }
        int res = 0;
        for (auto& p : mp) {
            int diff = p.first - 'a';
            if(p.first!='a'){
                res=max(res,26-diff);
            }
        }
        return res;
    }
};