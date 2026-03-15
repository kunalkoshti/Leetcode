class Solution {
public:
    int solve(vector<int>& nums){
        int n=nums.size();
        vector<int> lr(n);
        vector<int> rl(n);
        int diff=nums[1]-nums[0];
        lr[0]=1;
        lr[1]=2;
        for(int i=2;i<n;i++){
            if((nums[i]-nums[i-1])==diff){
                lr[i]=lr[i-1]+1;
            }
            else{
                lr[i]=2;
                diff=nums[i]-nums[i-1];
            }
        }
        rl[n-1]=1;
        rl[n-2]=2;
        diff=nums[n-1]-nums[n-2];
        for(int i=n-3;i>=0;i--){
            if((nums[i+1]-nums[i])==diff){
                rl[i]=rl[i+1]+1;
            }
            else{
                rl[i]=2;
                diff=nums[i+1]-nums[i];
            }
        }
        int res=-1;
        diff=nums[1]-nums[0];
        for(int i=2;i<n;i++){
            if((nums[i]-nums[i-1])==diff) continue;
            int prev=lr[i-1];
            res=max(res,prev+1);//base
            if(i==n-1) break;
            int a_=nums[i-1]+diff;
            if(nums[i+1]-a_== diff){
                if(i+2<n && (nums[i+2]-nums[i+1])==diff){
                    res=max(res,prev+1+rl[i+1]);
                }
                else{
                    res=max(res,prev+2);
                }
            }
            diff=nums[i]-nums[i-1];
        }
        if(res==-1) return n;
        return res;
    }
    int longestArithmetic(vector<int>& nums) {
        int res=solve(nums);
        reverse(nums.begin(),nums.end());
        res=max(res,solve(nums));
        return res;
    }
};