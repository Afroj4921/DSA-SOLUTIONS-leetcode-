class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n+1);

        for(auto a : times){
            adj[a[0]].push_back({a[1], a[2]});
        }
        vector<int> dist(n+1 , 1e9);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        dist[k] = 0;
        pq.push({0, k});

        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if(dis > dist[node]){
                continue;
            }
            for(auto it : adj[node]){
                int adjNode = it.first;
                int adjWt = it.second;
                if(dist[adjNode] > dis + adjWt){
                    dist[adjNode] = dis + adjWt;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        int ans = 0;
        for(int i=1; i<=n; i++){
            if(dist[i] == 1e9){
                return -1;
            }
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};