class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n=words.size();
        int ans=0;
        for(int i=0;i<n;i++){
            int sz=words[i].size();
            for(int j=i+1;j<n;j++){
                int siz=words[j].size();
                string tmp1="";
                for(int k=0;k<sz;k++)tmp1.push_back(words[j][k]);
                string tmp2="";
                for(int k=siz-sz;k<siz;k++)tmp2.push_back(words[j][k]);
                if(tmp1==tmp2 && tmp1==words[i])ans++;
            }
        }
        return ans;
    }
};