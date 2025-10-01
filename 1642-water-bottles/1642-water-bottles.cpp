class Solution {
public:
    int numWaterBottles(int n, int e) {
        if(e>n) return n;
        return e+numWaterBottles(n-e+1,e);
    }
};