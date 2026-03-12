typedef long long ll;
class Solution {
public:
    ll m1 = 1e9 + 9, m2 = 1e9 + 7;
    ll p1 = 53, p2 = 31;
    vector<pair<ll, ll>> pwr;
    void pre_process_pwr() {
        pwr[0] = {1, 1};
        for (int i = 1; i < pwr.size(); i++) {
            pwr[i].first = (pwr[i - 1].first * p1) % m1;
            pwr[i].second = (pwr[i - 1].second * p2) % m2;
        }
        return;
    }

    string longestDupSubstring(string s) {
        int n = s.length();
        int l = 1, r = n - 1;
        pair<int, int> res; //{idx,sz}
        pwr.resize(30002);
        pre_process_pwr();
        while (l <= r) {
            int sz = (l + r) / 2;
            set<pair<ll, ll>> hashes;
            ll hash1 = 0, hash2 = 0;
            bool found = false;
            for (int i = 0; i < sz - 1; i++) {
                hash1 = ((hash1 * p1) % m1 + (s[i] - 'a' + 1)) % m1;
                hash2 = ((hash2 * p2) % m2 + (s[i] - 'a' + 1)) % m2;
            }
            for (int i = sz - 1; i < n; i++) {
                if (i - sz >= 0) {
                    hash1 = (hash1 -
                             ((s[i - sz] - 'a' + 1) * pwr[sz - 1].first) % m1 +
                             m1) %
                            m1;
                    hash2 = (hash2 -
                             ((s[i - sz] - 'a' + 1) * pwr[sz - 1].second) % m2 +
                             m2) %
                            m2;
                }
                hash1 = ((hash1 * p1) % m1 + (s[i] - 'a' + 1)) % m1;
                hash2 = ((hash2 * p2) % m2 + (s[i] - 'a' + 1)) % m2;
                if (hashes.find({hash1, hash2}) == hashes.end()) {
                    hashes.insert({hash1, hash2});
                    continue;
                }
                res = {i - sz + 1, sz};
                found = true;
                break;
            }
            if (found)
                l = sz + 1;
            else
                r = sz - 1;
        }
        if (res.first == -1)
            return "";
        return string(string_view(s).substr(res.first, res.second));
    }
};