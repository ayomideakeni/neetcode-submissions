class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> blocked(m, vector<bool>(n,false));
        vector<vector<long long>> dp(m, vector<long long>(n, 0));

        for(auto& row : grid) dp.emplace_back(row.begin(), row.end());

        if(grid[0][0] == 1 || grid[m - 1][n - 1] == 1) return 0;
        
        

        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == 1){
                    blocked[i][j] = true;
                    grid[i][j] = 0;
                }
            }
        }

        
        dp[m - 1][n - 1] = 1;
        
        for(int r = m - 1; r >= 0; --r){
            for(int c = n - 1; c >= 0; --c){
                long long below = 0;
                long long left = 0;
                if(dp[r][c] == 0 && !blocked[r][c]){
                    if(r + 1 < m){
                        below = dp[r + 1][c];
                    }else below = 0;
                    if(c + 1 < n){
                        left = dp[r][c + 1];
                    }else left = 0;

                    dp[r][c] = (below + left);
                }
            }
        }

        return dp[0][0];
    }
};