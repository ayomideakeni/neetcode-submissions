class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size();
        int n = s2.size();
        int x = s3.size();
        if(n+m != x) return false;
        vector<vector<bool>>grid(m+1, vector<bool>(n+1, false));

        grid[m][n] = true;
        for(int i = m; i >=0; --i){
            for(int j = n; j >= 0; --j){
                if(i == m && j == n) continue;
                if(grid[i][j] == false){
                    bool up = (i < m && (grid[i+1][j] == true && (s1[i] == s3[i+j])));
                    bool left = (j < n && (grid[i][j+1] == true &&(s2[j] == s3[i+j])));
                        grid[i][j] = up || left;
                    }
                }
            }

        

        return grid[0][0];



    }
};