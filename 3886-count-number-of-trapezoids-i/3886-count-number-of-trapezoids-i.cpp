#define ll long long
ll mod = 1e9 + 7;
class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int, ll> mp;
        for (int i = 0; i < points.size(); i++) {
            if (mp.find(points[i][1]) != mp.end())
                mp[points[i][1]]++;
            else
                mp[points[i][1]] = 1;
        }
        for (auto& p : mp) {
            if (p.second < 2)
                p.second = 0;
            p.second = ((p.second * (p.second - 1)) / 2) % mod;
        }
        ll sum = 0;
        for (auto& p : mp) {
            if (p.second > 0)
                sum = (sum + p.second) % mod;
        }
        ll res = 0;
        for (auto& p : mp) {
            if (p.second < 1)
                continue;
            res = (res + (sum - p.second) * p.second) % mod;
        }
        ll inv2 = (mod + 1) / 2; // modular inverse of 2 when mod is prime
        return (res * inv2) % mod;
    }
};