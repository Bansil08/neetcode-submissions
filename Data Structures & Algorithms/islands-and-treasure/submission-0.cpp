class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        int mx=INT_MAX;
        queue<pair<int,pair<int,int>>>q;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    q.push({0,{i,j}});
                    vis[i][j]=1;
                }
            }
        }
        int dr[]={0,1,-1,0};
        int dc[]={1,0,0,-1};
        while(!q.empty()){
            int dist=q.front().first;
            int r=q.front().second.first;
            int c=q.front().second.second;
            q.pop();

            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];

                if(nr>=0 && nc>=0 && nr<n && nc<m && !vis[nr][nc] && grid[nr][nc]==mx){
                    q.push({dist+1,{nr,nc}});
                    vis[nr][nc]=1;
                    grid[nr][nc]=dist+1;
                }
            }            
        }
    }
};
