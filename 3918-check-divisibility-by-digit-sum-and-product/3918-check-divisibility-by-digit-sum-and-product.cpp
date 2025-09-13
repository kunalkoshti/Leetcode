class Solution {
public:
    pair<int,int> dig(int n,pair<int,int> p){
        if(n==0) return p;
        pair<int,int> res={p.first+(n%10),p.second*(n%10)};
        return dig(n/10,res);
    }
    bool checkDivisibility(int n) {
        pair<int,int> p=dig(n,{0,1});
        return (n%(p.first+p.second)==0);
    }
};