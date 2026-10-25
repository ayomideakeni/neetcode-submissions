class Solution {
public:

    
    int minimumEffortPath(vector<vector<int>>& h) {
        int m = h.size();
        int n = h[0].size();
        

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> q;

        vector<int>dC{-1,1,0,0};
        vector<int>dR{0,0,-1,1};
        
        q.push({0, 0,0});

        int minEffort = INT_MAX;

        while(!q.empty()){
            auto [effort,x,y] = q.top();
            if(x == m - 1 && y == n - 1) minEffort = min(effort, minEffort);
            

            q.pop();
            if(visited[x][y]) continue;
            visited[x][y] = true;

            for(int i = 0; i < 4; ++i){
                int nR = x + dR[i];
                int nC = y + dC[i];

                if(min(nR, nC) >= 0 && nR < m && nC < n && !visited[nR][nC]){
                   
                    int nEffort = max(effort,abs(h[nR][nC] - h[x][y]));
                    q.push({nEffort, nR, nC});
                    
                }
            }
        }

        
        return minEffort;
    }
};