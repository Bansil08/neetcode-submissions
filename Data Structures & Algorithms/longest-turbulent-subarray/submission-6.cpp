class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n=arr.size(), cnt = 1, ans = 1;
        for(int i=0; i<n-1; i++){
            if(i%2 == 1){
                if(arr[i] < arr[i+1]) cnt++;
                else cnt = 1;
            }else{
                if(arr[i] > arr[i+1]) cnt++;
                else cnt = 1;
            }
            ans = max(ans, cnt);
        }
        for(int i=0; i<n-1; i++){
            if(i%2 == 0){
                if(arr[i] < arr[i+1]) cnt++;
                else cnt = 1;
            }else{
                if(arr[i] > arr[i+1]) cnt++;
                else cnt = 1;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};