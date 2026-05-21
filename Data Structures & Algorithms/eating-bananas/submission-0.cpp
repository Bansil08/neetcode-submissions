class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int mx=0;
        int n=piles.size();
        for(int i=0;i<n;i++)mx=max(mx,piles[i]);
        int lo=1,hi=mx;
        int ans=INT_MAX;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            int cnt=0;
            for(int i=0;i<n;i++){
                if(piles[i]%mid)cnt=cnt+(piles[i]/mid)+1;
                else cnt=cnt+(piles[i]/mid);
            }
            if(cnt>h)lo=mid+1;
            if(cnt<=h){
                hi=mid-1;
                ans=min(ans,mid);
            }
        }
        return ans;
    }
};
