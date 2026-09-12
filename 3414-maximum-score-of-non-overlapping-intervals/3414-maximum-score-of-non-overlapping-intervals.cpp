class Solution {
public:
    struct Node{
        long long score = -1;
        vector<int> idxs;
    };

    int findNext(vector<vector<int>>& intervals, int end){
        int n = intervals.size();
        int l = 0, h = n-1;
        int result = n;
        while(l <= h){
            int mid = l + (h - l)/2;
            if(intervals[mid][0] > end){
                result = mid;
                h = mid-1;
            }else{
                l = mid + 1;
            }
        }
        return result;
    }

    // reccursion + memoiztion
    Node f(vector<vector<int>>& intervals, int i, int n, int k, vector<int>& nextIdx, vector<vector<Node>>& dp){
        if(k == 0 || i >= n){
            return Node();
        }
        if(dp[i][k].score != -1) return dp[i][k];

        Node notTake = f(intervals, i+1, n, k, nextIdx, dp);

        int wt = intervals[i][2];
        int idx = intervals[i][3];
        int j = nextIdx[i];

        Node temp = f(intervals, j, n, k-1, nextIdx, dp);
        Node take;
        take.score = temp.score + wt;
        take.idxs = temp.idxs;
        take.idxs.push_back(idx);
        sort(take.idxs.begin(), take.idxs.end());

        Node result;
        if(notTake.score > take.score){
            result = notTake;
        }else if(notTake.score < take.score){
            result = take;
        }else{
            result = (notTake.idxs < take.idxs) ? notTake : take;
        }

        return dp[i][k] = result;
    }


    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        // storing the original index in the vector
        for(int i=0; i<n; i++){
            intervals[i].push_back(i);
        }
        sort(intervals.begin(), intervals.end());

        vector<int> nextIdx(n);
        for(int i=0; i<n; i++){
            int end = intervals[i][1];
            nextIdx[i] = findNext(intervals, end);
        }
        int k = 4;
        vector<vector<Node>> dp(n+1, vector<Node>(k + 1));

        for(int i=n-1; i>=0; i--){
            int wt = intervals[i][2];
            int idx = intervals[i][3];
            int j = nextIdx[i];

            for(int k=1; k<=4; k++){
                Node notTake = dp[i+1][k];

                Node temp = dp[j][k-1];
                Node take;
                take.score = temp.score + wt;
                take.idxs = temp.idxs;
                take.idxs.push_back(idx);
                sort(take.idxs.begin(), take.idxs.end());

                Node result;
                if(notTake.score > take.score){
                    result = notTake;
                }else if(notTake.score < take.score){
                    result = take;
                }else{
                    result = (notTake.idxs < take.idxs) ? notTake : take;
                }

                dp[i][k] = result;
            }
        }
        return dp[0][4].idxs;
    }
};