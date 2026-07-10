class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& vis,int cnt){
        vis[i][j]=1;
        cnt++;
        int di[]={0,1,-1,0};
        int dj[]={1,0,0,-1};

        for(int k=0;k<4;k++){
            int ni=i+di[k];
            int nj=j+dj[k];

            if(ni>=0 && nj>=0 && ni<grid.size() && nj<grid[0].size() && grid[ni][nj]==1 && !vis[ni][nj])cnt=cnt+dfs(ni,nj,grid,vis,0);
        }
        return cnt;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && (!vis[i][j])){
                    ans=max(ans,dfs(i,j,grid,vis,0));
                }
            }
        }
        return ans;
    }
};
