class Solution {
public:
    int minDistance(string word1, string word2){
        int m = word1.size();
        int n = word2.size();
        int lval = 0;
        int dval = 0;
        int diagval = 0;

        vector<vector<int>>dp(m+1, vector<int>(n+1, 0));
        for(int i = 0; i <= m; ++i) dp[i][0] = i;
        for(int j = 0; j <= n; ++j) dp[0][j] = j;

        for(int i = 1; i <= m; ++i){
            for(int j = 1; j <= n; ++j){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    if(i > 0) lval = dp[i-1][j]; 
                    if(j > 0) dval = dp[i][j-1];
                    if(lval && dval) diagval = dp[i-1][j-1];
                       
                    dp[i][j] = 1 + min({lval, dval,diagval});
                }
            }
        }

        return dp[m][n];
    }
};
