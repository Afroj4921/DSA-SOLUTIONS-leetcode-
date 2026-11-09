class Solution {
public:
    typedef pair<int, int> P;
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        int n = arrival.size();
        set<int> available_servers;
        
        for(int i=0; i<k; i++){
            available_servers.insert(i);
        }

        priority_queue<P, vector<P>, greater<P>> busyServers;//(finishTime, serverId)

        vector<int> countReq(k, 0);
        vector<int> result;

        for(int i=0; i<n ;i++){
            int time = arrival[i];
            while(!busyServers.empty() && busyServers.top().first <= time){
                int server = busyServers.top().second;
                busyServers.pop();
                available_servers.insert(server);
            }
            if(available_servers.empty()){
                continue;
            }

            int target = i%k;
            auto it = available_servers.lower_bound(target);

            if(it == available_servers.end()){
                it = available_servers.begin();
            }

            int target_server = *it;
            available_servers.erase(it);

            busyServers.push({time + load[i], target_server});

            countReq[target_server]++;
        }

        int maxNumOfReq = *max_element(countReq.begin(), countReq.end());

        for(int i=0; i<k ; i++){
            if(countReq[i] == maxNumOfReq){
                result.push_back(i);
            }
        }
        return result;
    }
};