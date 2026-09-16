class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();

        int rprev = 0;
        for(int row1 = 0; row1 < n; ++row1){
            grid[0][row1] += rprev;
            rprev = grid[0][row1];
        }

        int cprev = 0;
        for(int col1 = 0; col1 < m; ++col1){
            grid[col1][0] += cprev;
            cprev = grid[col1][0];
        }

        for(int r = 1; r < m; ++r){
            for(int c = 1; c < n; ++c){
                grid[r][c] = min(grid[r][c] + grid[r- 1][c], grid[r][c] + grid[r][c - 1]);
            }
        }

        return grid[m-1][n-1];
    }
};