class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<flights.size();i++){
            int u=flights[i][0];
            int v=flights[i][1];
            int wt=flights[i][2];

            adj[u].push_back({v,wt});
        }
        vector<vector<int>>dist(n,vector<int>(k+2,INT_MAX));
        dist[src][0]=0;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;

        pq.push({0,{src,0}});

        while(!pq.empty()){
            int nk=pq.top().second.second;
            int node=pq.top().second.first;
            int cost=pq.top().first;
            pq.pop();

            if(nk>=k+1)continue;
            if(dist[node][nk]<cost)continue;

            for(auto it : adj[node]){
                int adjnode=it.first;
                int dis=it.second;

                if(dist[adjnode][nk+1]>dis+cost){
                    dist[adjnode][nk+1]=dis+cost;
                    pq.push({dis+cost,{adjnode,nk+1}});
                }
            }
        }
        int ans=INT_MAX;
        for(int i=0;i<k+2;i++)ans=min(ans,dist[dst][i]);
        if(ans==INT_MAX)return -1;
        return ans;
    }
};
