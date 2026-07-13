class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        int l=0,r=0;
        deque<int>dq;
        vector<int>ans;
        while(r<n){
            if(dq.empty())dq.push_back(r);
            else{
                int val=dq.front();
                if(nums[r]>nums[dq.back()]){
                    while(!dq.empty() && nums[r]>nums[dq.back()])dq.pop_back();
                    dq.push_back(r);
                }
                else{
                    dq.push_back(r);
                }
                int len=r-l+1;
                if(len>k){
                    if(!dq.empty() && dq.front()==l){
                        dq.pop_front();
                    }
                    l++;
                }
            }
            int len=r-l+1;
            if(len==k)ans.push_back(nums[dq.front()]);
            r++;
        }
        return ans;
    }
};
