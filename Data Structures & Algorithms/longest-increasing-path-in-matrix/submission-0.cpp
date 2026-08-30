class Solution {
public:

    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = 0;

        vector<vector<int>> outdegree(m, vector<int>(n));

        vector<int> dR{-1,1,0,0};
        vector<int> dC{0,0,-1,1};
        queue<pair<int,int>> q;
        vector<vector<int>> dp(m, vector<int>(n,0));


        for(int r = 0; r < m; ++r){
            for(int c = 0; c < n; ++c){
                pair<int,int> cur = {r,c};
                for(int i = 0; i < 4; ++i){
                    int nR = r + dR[i];
                    int nC = c + dC[i];
                    if((min(nR, nC) >= 0 && nR < m && nC < n) && (matrix[nR][nC] > matrix[r][c])){
                        if(matrix[nR][nC] > matrix[r][c]) ++outdegree[r][c];
                    }      
                }
                if(outdegree[r][c] == 0) q.push({r,c});
                dp[r][c] = 1;
            }
        }

        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();
            for(int i = 0; i < 4; ++i){
                int nR = r + dR[i];
                int nC = c + dC[i];
                if((min(nR, nC) >= 0 && nR < m && nC < n) && matrix[nR][nC] < matrix[r][c]){
                    --outdegree[nR][nC];
                    if(outdegree[nR][nC] == 0) q.push({nR, nC});
                    dp[nR][nC] = max(dp[nR][nC], dp[r][c] + 1);
                }
                ans = max(ans, dp[r][c]);
            }

        }
        return ans;

    }
};