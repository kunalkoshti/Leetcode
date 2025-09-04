class Solution {
public:
    int findClosest(int x, int y, int z) {
        int t1 = abs(z - x);
        int t2 = abs(z - y);
        if (t1 < t2)
            return 1;
        if (t2 < t1)
            return 2;
        return 0;
    }
};