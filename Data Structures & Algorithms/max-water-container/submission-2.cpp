class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n=heights.size();
        int l=0,r=n-1;
        int ans=0;
        while(l<r){
            if(heights[r]>heights[l]){
                ans=max(ans,heights[l]*(r-l));
                l++;
            }
            else{
                ans=max(ans,heights[r]*(r-l));
                r--;
            }
        }
        return ans;
    }
};
