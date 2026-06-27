class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue<pair<int,int>>pq;
        vector<int>ans;
        unordered_map<int,int>mpp;
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }
        for(auto it : mpp){
            pq.push({it.second,it.first});
        }
        while(k--){
            int element=pq.top().second;
            ans.push_back(element);
            pq.pop();
        }
        return ans;
    }
};
