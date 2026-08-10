class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n +1);
        //cost,dst
        unordered_set<int> visited;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> minHeap;

        for(auto node : times){
            adj[node[0]].push_back({node[2], node[1]});
        }
        int maxTime = 0;

        minHeap.push({0, k});

        while(!minHeap.empty()){
            auto [time, dst] = minHeap.top();
            minHeap.pop();

            if(visited.find(dst) != visited.end()) continue;
            maxTime = max(maxTime, time);
            visited.insert(dst);

            for(auto [nCost, nNode] : adj[dst]){
                minHeap.emplace(nCost+time, nNode);
            }
            
        }
        return (visited.size() == n) ? maxTime : -1;


        
    }
};