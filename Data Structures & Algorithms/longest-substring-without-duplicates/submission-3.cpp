class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len=0;
        int mxlen=0;
        int n=s.size();
        int l=0,r=0;
        unordered_map<char,int>mpp;
        while(r<n){
            if(l==r){
                mpp[s[r]]++;
                r++;
                len=r-l;
                mxlen=max(mxlen,len);
                continue;
                }
                while(mpp.find(s[r])!=mpp.end()){
                    mpp[s[l]]--;
                    if(mpp[s[l]]==0)mpp.erase(s[l]);
                    l++;
                }
                mpp[s[r]]++;
                len=r-l+1;
                mxlen=max(mxlen,len);
                r++;
        }
        return mxlen;
    }
};
