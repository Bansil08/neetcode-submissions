class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n=arr.size();
        int l=0,r=1;
        int prev=-1;
        int ans=1;
        while(r<n){
            if(prev==-1){
                if(arr[r-1]<arr[r]){
                    prev=0;
                    r++;
                    continue;
                }
                else if(arr[r-1]>arr[r]){
                    prev=1;
                    r++;
                    continue;
                }
                else{
                  ans=max(ans,r-l);
                  l=r;
                  r++;
                  continue;  
                }
            }
            if(arr[r-1]<arr[r] && (prev==1 || prev==-1)){
                prev=0;
                r++;
                continue;
            }
            else if(arr[r-1]>arr[r] && (prev==0 || prev==-1)){
                    prev=1;
                    r++;
                    continue;
                }
                else{
                  ans=max(ans,r-l); 
                  if(arr[r-1] > arr[r]){
                    prev = 1;
                    l = r-1;
                  }else if(arr[r-1] < arr[r]){
                    prev = 0;
                    l = r-1;
                  }else{
                    prev = -1;
                    l = r;
                  }
                  r++;
                  continue;
                }
            }
            ans = max(ans, r-l);
            return ans;
        }
    };
