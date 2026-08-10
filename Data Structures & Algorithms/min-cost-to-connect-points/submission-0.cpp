class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        map<pair<int,int>,int> visited;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> minHeap;
        //cost,node[x,y]
        int finalCost = 0;

        minHeap.push({0, {points[0][0], points[0][1]}});

        while(!minHeap.empty()){
            if(visited.size() == n)break;
            auto [x,y] = minHeap.top().second;
            auto cCost = minHeap.top().first;
            minHeap.pop();
            if(visited.find({x,y}) != visited.end()) continue;
            visited[{x,y}] = cCost;
            finalCost += cCost;

            for(auto p : points){
                int x1 = p[0];
                int y1 = p[1];

                if(visited.find({x1,y1}) != visited.end()) continue;
                else{
                    int cost = (abs(x - x1)+abs(y - y1));
                    minHeap.emplace(cost, make_pair(x1,y1));
                }
            }
        }
        return finalCost;
    }
};