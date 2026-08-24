class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        // elevation, x,y
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> minHeap;
        int n = grid.size();
        vector<vector<bool>> visited(n, vector<bool>(n));
        vector<int> dR{-1, 1, 0, 0};
        vector<int> dC{0, 0, -1, 1};
        minHeap.push({grid[0][0],0,0});
        int ans = 0;

        while(!minHeap.empty()){
            auto [elev, x, y] = minHeap.top();
            minHeap.pop();
            ans = max(ans, elev);
            if (x == n - 1 && y == n - 1) return ans;
                for (int i = 0; i < 4; ++i) {
                    int r = x + dR[i];
                    int c = y + dC[i];
                    if (min(r, c) >= 0 && max(r, c) < n) {
                        if (!visited[r][c]) minHeap.push({grid[r][c], r, c});
                    }
            }
            visited[x][y] = true;
        }
            
        

        return ans;
    }
};