class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double ans=0;
        int n=nums1.size();
        int m=nums2.size();
        if((n+m)%2){
            int mid=(n+m)/2;
            int cnt=0;
            int p1=0,p2=0;
            while(p1<nums1.size() && p2<nums2.size()){
                if(nums1[p1]>nums2[p2]){
                    if(cnt==mid){
                        ans=nums2[p2];
                        return ans;
                    }
                    cnt++;
                    p2++;
                }
                else{
                    if(cnt==mid){
                        ans=nums1[p1];
                        return ans;
                    }
                    cnt++;
                    p1++;
                }
            }
            if(p1==nums1.size()){
                while(p2<nums2.size()){
                if(cnt==mid){
                    ans=nums2[p2];
                    return ans;
                }
                cnt++;
                p2++;
                }
            }
            else if(p2==nums2.size()){
                while(p1<nums1.size()){
                if(cnt==mid){
                    ans=nums1[p1];
                    return ans;
                }
                cnt++;
                p1++;
            }
            }
        }
        else{
            int mid=(n+m)/2;
            int cnt=0;
            int p1=0,p2=0;
              while(p1<nums1.size() && p2<nums2.size()){
                if(nums1[p1]>nums2[p2]){
                    if(cnt==mid-1){
                        ans=ans+nums2[p2];
                    }
                    else if(cnt==mid){
                        ans=ans+nums2[p2];
                        ans=ans/2;
                        return ans;
                    }
                    cnt++;
                    p2++;
                }
                else{
                    if(cnt==mid-1){
                        ans=ans+nums1[p1];
                    }
                    else if(cnt==mid){
                        ans=ans+nums1[p1];
                        ans=ans/2;
                        return ans;
                    }
                    cnt++;
                    p1++;
                }
            }
             if(p1==nums1.size()){
                while(p2<nums2.size()){
                if(cnt==mid-1)ans=ans+nums2[p2];
                else if(cnt==mid){
                    ans=ans+nums2[p2];
                    ans=ans/2;
                    return ans;
                }
                cnt++;
                p2++;
                }
            }
            else if(p2==nums2.size()){
                while(p1<nums1.size()){
                if(cnt==mid-1)ans=ans+nums1[p1];    
                else if(cnt==mid){
                    ans=ans+nums1[p1];
                    ans=ans/2;
                    return ans;
                }
                cnt++;
                p1++;
            }
            }
        }
        return ans;
    }
};
