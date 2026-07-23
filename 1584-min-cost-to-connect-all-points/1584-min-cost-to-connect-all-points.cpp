class Solution {
public:
    int manDist(vector<vector<int>>& points, int p1, int p2){
        return abs(points[p1][0] - points[p2][0]) + abs(points[p1][1] - points[p2][1]);
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        int mstCost = 0;
        vector<bool> inMst(n, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});

        while(!pq.empty()){
            int node = pq.top().second;
            int wt = pq.top().first;

            pq.pop();
            if(!inMst[node]){
                inMst[node] = true;
                mstCost += wt;

                for(int i=0; i<n; i++){
                    if(!inMst[i]){
                        int edWt = manDist(points, node, i);
                        pq.push({edWt, i});
                    }
                }
            }
        }
        return mstCost;
    }
};