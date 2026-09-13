class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        bool row1Zero = false;
        bool col1Zero = false;

        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (matrix[r][c] == 0) {
                    if(r == 0) row1Zero = true;
                    if(c == 0) col1Zero = true;
                    matrix[r][0] = 0;
                    matrix[0][c] = 0;
                }
            }
        }

        for (int r1 = 1; r1 < m; ++r1) {
            for (int c1 = 1; c1 < n; ++c1) {
                if (matrix[r1][0] == 0 || matrix[0][c1] == 0) {
                    matrix[r1][c1] = 0;
                }
            }
        }

        if(col1Zero){
            for(int row = 0; row < m; ++row){
                matrix[row][0] = 0;
            }
        }

        if(row1Zero){
            for(int col = 0; col < n; ++col){
                matrix[0][col] = 0;
            }
        }
    }
};