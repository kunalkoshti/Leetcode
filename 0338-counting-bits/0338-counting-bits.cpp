class Solution {
public:
    int countSetBits(int n){
        int count=0;
        while(n){
            n=n&(n-1);
            count++;
        }
        return count;
    }
    vector<int> countBits(int n) {
        vector<int> res;
        for(int i=0;i<=n;i++){
            res.push_back(countSetBits(i));
        }
        return res;
    }
};