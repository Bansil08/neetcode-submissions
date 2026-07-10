class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>& vis,int n,int m,vector<vector<char>>& grid){
        int di[]={0,1,-1,0};
        int dj[]={1,0,0,-1};
        vis[i][j]=1;
        for(int k=0;k<4;k++){
            int ni=i+di[k];
            int nj=j+dj[k];

            if(ni>=0 && nj>=0 && ni<n && nj<m && !vis[ni][nj] && grid[ni][nj]=='1')dfs(ni,nj,vis,n,m,grid);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    if(vis[i][j]!=1){
                        ans++;
                        dfs(i,j,vis,n,m,grid);
                        }
                }
            }
        }
        return ans;
    }
};
