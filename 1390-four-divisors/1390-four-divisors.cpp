class Solution {
public:
    int n=1e5;
    int sumFourDivisors(vector<int>& nums) {
        vector<bool> isPrime(n + 1, 1);
        for (int i = 2; i * i <= n; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= n; j += i) {
                    isPrime[j] = 0;
                }
            }
        }
        vector<int> div4(n+1,0);
        for (int i = 2; i * i <= n; i++) {
            if (isPrime[i]) {
                for (int j = i * (i+1); j <= n; j += i) {
                    if(isPrime[j/i] || j==(i*i*i)) div4[j]=1+j+i+(j/i);
                }
            }
        }
        int res=0;
        for(int i=0;i<nums.size();i++){
            res+=div4[nums[i]];
        }
        return res;
    }
};