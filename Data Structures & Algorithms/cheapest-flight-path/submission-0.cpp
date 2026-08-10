class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        using nInfo = tuple<int,int,int>;
        // cost,to
        vector<vector<pair<int,int>>> adj(n);
        vector<int> minStops(n, INT_MAX);
        priority_queue<nInfo, vector<nInfo>, greater<>> minHeap;

        for(auto& f : flights){
            adj[f[0]].push_back({f[1], f[2]});
        }

        minHeap.push({0, src, 0});
        

        while(!minHeap.empty()){
            auto [currentCost, node, stops] = minHeap.top();
            minHeap.pop();

            if(node == dst) return currentCost;
            if(stops > k) continue;
            if(stops >= minStops[node]) continue;
            minStops[node] = stops;
            for(auto& [next, price] : adj[node]){
                minHeap.push({price + currentCost, next, stops+1});
            }
        }

        
        return -1;
        

    }
};