class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size();
        int m=t.size();
        unordered_map<char,int>mpp;
        for(int i=0;i<m;i++)mpp[t[i]]++;

        int l=0,r=0;
        int cnt=0;
        int ans=INT_MAX;
        int st=-1;
        while(r<n){
            bool f=0;
            if(mpp[s[r]]>0){
                cnt++;
                }
                mpp[s[r]]--;
                
            while(cnt==m){
                if(ans>r-l+1){
                    ans=r-l+1;
                    st=l;
                }
                mpp[s[l]]++;
                if(mpp[s[l]]>0)cnt--;
                l++;

            }
            r++;
        }
        if(st==-1)return "";
        return s.substr(st,ans);
    }
};
