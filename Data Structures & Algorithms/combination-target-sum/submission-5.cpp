class Solution {
public:
vector<vector<int>>ans;

    void solve(int idx,vector<int>& nums,int target,vector<int> temp){
        if(target<0)return;
        if(target==0){ ans.push_back(temp); return; }
        if(idx==nums.size()) return;
        solve(idx+1,nums,target,temp);
        while(target-nums[idx] >= 0){
            target -= nums[idx];
            temp.push_back(nums[idx]);
            solve(idx+1, nums, target, temp);
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int>temp;
        solve(0,nums,target,temp);
        return ans;
    }
};
