class Solution {
public:
    bool isCycleDFS(int src, vector<bool> &vis, vector<bool> &recPath, vector<vector<int>>& adj){
        vis[src] = true;
        recPath[src] = true;

        for(int v : adj[src]){
            if(!vis[v]){
                if(isCycleDFS(v, vis, recPath, adj)){
                    return true;
                }
            }else if(recPath[v]){
                return true;
            }
        }

        recPath[src] = false;
        return false;
    }

    bool canFinish(int n, vector<vector<int>>& edges) {
        vector<bool> vis(n, false);
        vector<bool> recPath(n, false);
        vector<vector<int>> adj(n);

        for(auto &a : edges){
            adj[a[1]].push_back(a[0]);
        }

        for(int i=0; i<n; i++){
            if(!vis[i]){
                if(isCycleDFS(i, vis, recPath, adj)){
                    return false;
                }
            }
        }
        return true;
    }
};