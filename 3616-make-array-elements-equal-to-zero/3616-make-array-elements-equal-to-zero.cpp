class Solution {
public:
    bool check(vector<int>& nums){
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0) return false;
        }
        return true;
    }
    bool travel(vector<int>& nums, int curr, int dir){
        if(curr>=nums.size() || curr<0){
            return check(nums);
        }
        if(nums[curr]==0){
            return travel(nums,curr+dir,dir);
        }
        nums[curr]--;
        dir*=-1;
        return travel(nums,curr+dir,dir);

    }
    int countValidSelections(vector<int>& nums) {
        int res=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                vector<int> tmp=nums;
                if(travel(tmp,i,1)) res++;
                tmp=nums;
                if(travel(tmp,i,-1)) res++;
            }
        }
        return res;
    }
};