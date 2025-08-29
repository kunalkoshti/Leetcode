class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        int n=nums.size();
        if(n%k!=0) return false;
        int cap=n/k;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            if(mp.find(nums[i])==mp.end()) mp[nums[i]]=1;
            else{
                mp[nums[i]]++;
            }
        }
        for(auto &p:mp){
            if(p.second>cap) return false;
        }
        return true;
    }
};