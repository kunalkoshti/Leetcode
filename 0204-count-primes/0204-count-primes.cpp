class Solution {
public:
    int countPrimes(int n) {
        /*vector<bool> isPrime(n + 1, 1);
        for (int i = 2; i * i <= n; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= n; j += i) {
                    isPrime[j] = 0;
                }
            }
        }
        int res = 0;
        for(int i = 2; i < n; i++) {
            if (isPrime[i])
                res++;
        }
        return res;*/
        vector<int> isPrime(n+1,0);
        vector<int> primes;
        for(int i=2;i<=n;i++){
            if(isPrime[i]==0){
                isPrime[i]=i;
                primes.push_back(i);
            }
            for(int j=0;j<primes.size() && i*primes[j]<=n;j++){
                isPrime[i*primes[j]]=primes[j];
            }
        }
        int res=0;
        for(int i=2;i<n;i++){
            if(isPrime[i]==i) res++;
        }
        return res;
    }
};