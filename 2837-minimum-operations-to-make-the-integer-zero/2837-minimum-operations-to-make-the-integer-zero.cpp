class Solution {
public:
    int ct(long long n){
        if(n==0) return 0;
        if(n%2==0) return ct(n/2);
        return 1+ct(n/2);
    }
    int makeTheIntegerZero(int num1, int num2) {
        if(num1<=num2) return -1;
        for(int i=1;i<61;i++)
        {
            long long sum=(long long)num1-(long long)i*num2;
            if(sum<=0) return -1;
            cout<<ct(sum)<<" ";
            if(sum>=i && ct(sum)<=i) return i;
        }
        return -1;
    }
};