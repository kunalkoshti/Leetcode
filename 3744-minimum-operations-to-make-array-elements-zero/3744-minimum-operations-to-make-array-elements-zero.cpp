#define ll long long
class Solution {
public:
    int ops(ll n) {
        if (n == 0)
            return 0;
        return 1 + ops(n / 4);
    }

ll pwr4(int n) {
    if (n == 0) return 1;
    ll half = pwr4(n / 2);
    if (n % 2 == 0) return half * half;
    return 4 * half * half;
}

    ll process(ll l, ll r) {
        ll sum = 0;
        int x1 = ops(l);
        cout<<x1<<endl;
        ll next = pwr4(x1);
        cout<< next<<endl;
        ll prev = l;
        while (next <= r) {
            sum += (next - prev) * (ll)x1;
            prev = next;
            next = 4 * next;
            x1++;
        }
        sum += (r - prev + 1) * (ll)x1;
        cout<<sum<<" ";
        return (sum % 2) + (sum / 2);
    }
    long long minOperations(vector<vector<int>>& queries) {
        ll res = 0;
        for (int i = 0; i < queries.size(); i++) {
            res += process((ll)queries[i][0], (ll)queries[i][1]);
        }
        return res;
    }
};