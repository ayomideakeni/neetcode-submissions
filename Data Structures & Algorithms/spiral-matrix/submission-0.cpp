class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> result;

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        int dir = 0;

        

        int r = 0;
        int c = 0;

        int dR[] = {0, 1, 0, -1};
        int dC[] = {1, 0, -1, 0};
        for(int count = 0; count < m * n; ++count){
            result.push_back(matrix[r][c]);
            visited[r][c] = true;

            int nR = r + dR[dir];
            int nC = c + dC[dir];
            
            if((min(nR, nC) < 0 || nR >= m || nC >= n || visited[nR][nC])){

                dir = (dir + 1) % 4;
                
                nR = r + dR[dir];
                nC = c + dC[dir];

            }

            r = nR;
            c = nC;
        }

        return result;
    }
};