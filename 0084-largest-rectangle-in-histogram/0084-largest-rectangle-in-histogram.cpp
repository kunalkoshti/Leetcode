class Solution {
public:
    vector<int> dist(vector<int> &heights)
    {
        int n=heights.size();
        vector<int> dpl(n,1); 
        stack<pair<int,int>> s;
        s.push({heights[0],0});
        for(int i=1;i<n;i++)
        {
            if(heights[i]>s.top().first) s.push({heights[i],i});
            else{
                    while(!s.empty() && s.top().first>=heights[i]){
                        s.pop();
                    }
                    if(s.empty())dpl[i]+=i;
                    else{
                        dpl[i]=i-s.top().second;
                    }
                    s.push({heights[i],i});

            }
        }
        return dpl;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> dpl=dist(heights);
        reverse(heights.begin(),heights.end()); 
        vector<int> dpr=dist(heights);
        reverse(dpr.begin(),dpr.end());
        reverse(heights.begin(),heights.end()); 
        int res=0;
        for(int i=0;i<n;i++)
        {
            res=max(res,(dpl[i]+dpr[i]-1)*heights[i]);
        }
        return res;
    }
};