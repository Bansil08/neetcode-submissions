class Solution {
public:
    int maxScore(string s) {
        int s1=0;
        int idx=-1;
        int ms=INT_MAX;
        for(int i=0;i<s.size()-1;i++){
            if(s[i]=='0')s1--;
            else s1++;
            if(ms>s1){
                ms=s1;
                idx=i;
            }
        }
        int ans=0;
        for(int i=0;i<=idx;i++)if(s[i]=='0')ans++;
        for(int i=idx+1;i<s.size();i++)if(s[i]=='1')ans++;
        return ans;
    }
};