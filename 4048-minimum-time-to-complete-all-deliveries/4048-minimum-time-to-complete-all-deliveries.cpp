#define ll long long
class Solution {
public:
    void swap(int* a1, int* a2) {
        int t = *a1;
        *a1 = *a2;
        *a2 = t;
        return;
    }
    int gcd(int a1, int a2) {
        if (a1 > a2) {
            swap(&a1, &a2);
        }
        if (a2 % a1 == 0)
            return a1;
        return gcd(a1, a2 % a1);
    }
    ll bs(ll l, ll ri, vector<int>& d, vector<int>& r_, int r) {
        ll lo = l, hi = ri;
        ll d1 = d[0], d2 = d[1], r1 = r_[0], r2 = r_[1];
        while (lo <= hi) {
            ll mid = lo + (hi - lo) / 2;
            ll alpha = mid / r;
            ll x1 = mid / r1, x2 = mid / r2;
            ll v1 = d1 - x2 + alpha, v2 = d2 - x1 + alpha;
            if (v1 < 0)
                v1 = 0;
            if (v2 < 0)
                v2 = 0;
            if (v1 + v2 > mid - x1 - x2 + alpha)
                lo = mid + 1;
            else {
                hi = mid - 1;
            }
        }
        return lo;
    }
    long long minimumTime(vector<int>& d_, vector<int>& r_) {
        ll d = d_[0] + d_[1];
        int g = gcd(r_[0], r_[1]);
        ll r = ((ll)r_[0] * r_[1]) / g;
        ll lo = d, hi = 2 * d;
        return bs(lo, hi, d_, r_, r);
    }
};