class Solution {
public:
    long long countCommas(long long n) {
        if(n<1000) return 0;
        if(n<(1LL*1e6)){
            return (n-(1LL*1e3)+1);
        }
        if(n<(1LL*1e9)){
            return (n-(1LL*1e6)+1)*2+countCommas((1LL*1e6)-1);
        }
        if(n<(1LL*1e12)){
            return (n-(1LL*1e9)+1)*3+countCommas((1LL*1e9)-1);
        }
        if(n<(1LL*1e15)){
            return (n-(1LL*1e12)+1)*4+countCommas((1LL*1e12)-1);
        }
        return 5+countCommas(n-1);
    }
};