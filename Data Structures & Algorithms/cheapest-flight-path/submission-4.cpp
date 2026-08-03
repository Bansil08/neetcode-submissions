class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int sz=flights.size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        vector<vector<int>>dist(n,vector<int>(k+2,INT_MAX));
        pq.push({0,{src,0}});
        dist[src][0]=0;

       vector<pair<int,int>>adj[n];
        for(int i=0;i<sz;i++){
            int u=flights[i][0];
            int v=flights[i][1];
            int val=flights[i][2];
            adj[u].push_back({v,val});
        }

        while(!pq.empty()){
            int cost=pq.top().first;
            int node=pq.top().second.first;
            int nk=pq.top().second.second;
            pq.pop();

            if(nk==k+1)continue;
    
            for(auto it : adj[node]){
                int adjnode=it.first;
                int price=it.second;

                if(nk>=k+1)continue;
                if(cost+price<dist[adjnode][nk+1]){
                    dist[adjnode][nk+1]=cost+price;
                    pq.push({cost+price,{adjnode,nk+1}});
                }
            }
        }
        int ans=INT_MAX;

        for(int i=0;i<k+2;i++)ans=min(ans,dist[dst][i]);
        if(ans==INT_MAX)return -1;
        return ans;
    }
};
