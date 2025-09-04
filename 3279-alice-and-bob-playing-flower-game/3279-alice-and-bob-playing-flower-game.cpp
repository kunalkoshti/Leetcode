#define ll long long
class Solution {
public:
    long long flowerGame(int n, int m) {
        int e1, o1, e2, o2;
        o1 = e1 = n / 2, o2 = e2 = m / 2;
        if (n % 2 != 0)
            o1++;
        if (m % 2 != 0)
            o2++;
        return (ll)o1 * (ll)e2 + (ll)o2 * (ll)e1;
    }
};