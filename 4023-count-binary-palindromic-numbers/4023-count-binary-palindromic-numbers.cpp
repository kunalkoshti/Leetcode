class Solution {
public:

    long long makePal(long long p, int len) {
        long long pal = p;
        long long q = (len % 2 == 0) ? p : (p >> 1);
        while (q > 0) {
            pal = (pal << 1) | (q & 1);
            q >>= 1;
        }
        return pal;
    }
    int countBinaryPalindromes(long long n) {
        if (n == 0) return 1;
        int bits = 64 - __builtin_clzll(n);
        long long res = 1;
        for (int len = 1; len < bits; len++) {
            res += 1LL << ((len - 1) / 2);
        }
        int half = (bits + 1) / 2;
        long long start = 1LL << (half - 1);
        long long end   = (1LL << half) - 1;

        long long lo = start, hi = end, best = start - 1;
        while (lo <= hi) {
            long long mid = (lo + hi) >> 1;
            long long pal = makePal(mid, bits);
            if (pal <= n) {
                best = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        if (best >= start) res += (best - start + 1);
        return (int)res;
    }
};