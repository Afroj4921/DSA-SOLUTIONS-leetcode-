class Solution {
public:
    typedef pair<int, int> P;//wt, idx
    typedef tuple<long , int, int> T;//finishTime, wt, idx

    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();
        int m = tasks.size();

        priority_queue<P, vector<P>, greater<P>> freeServers;//wt, idx

        priority_queue<T, vector<T>, greater<T>> busyServers;//finishTime, wt, idx

        vector<int> result(m);

        for(int i=0; i<n; i++){
            freeServers.push({servers[i], i});
        }

        // move free servers from busy to freeServers;
        for(int i=0; i<m; i++){
            while(!busyServers.empty() && get<0>(busyServers.top()) <= i){
                auto[finishTime, wt, idx] = busyServers.top();
                busyServers.pop();
                freeServers.push({wt, idx});
            }

            if(freeServers.empty()){
                auto[finishTime, wt, idx] = busyServers.top();
                busyServers.pop();
                result[i] = idx;
                busyServers.push({finishTime + tasks[i], wt, idx});
            }else{
                auto[wt, idx] = freeServers.top();
                freeServers.pop();
                result[i] = idx;
                busyServers.push({i + tasks[i], wt, idx});

            }
        }
        return result;
    }
};