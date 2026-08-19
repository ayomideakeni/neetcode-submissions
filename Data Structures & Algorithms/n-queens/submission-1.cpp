class Solution {
public:

    vector<vector<string>> result;
    vector<vector<int>> boards;

    void backtrack(vector<int>& board,vector<bool>& cols,vector<bool>& diag1,vector<bool>& diag2, int r, int n){
        
        if(r == n){
            vector<string> currentBoard;
            for(int i = 0; i < n; ++i){
                string row(n, '.');
                row[board[i]] = 'Q';
                currentBoard.push_back(row);
            }
            result.push_back(currentBoard);
            return;
        }

        for(int c = 0; c < n; ++c){
            if(cols[c] ||  diag1[r + c] || (diag2[r - c + n - 1])){
            continue;
            }

            board[r] = c; 
            cols[c] = diag1[r + c] = diag2[r - c + n - 1] = true;
            backtrack(board, cols, diag1, diag2, r + 1, n);
        
            cols[c] = diag1[r + c] = diag2[r - c + n - 1] = false;
        }
        
    }

    
    vector<vector<string>> solveNQueens(int n) {
        vector<int> board(n);
        vector<bool> cols(n);
        vector<bool> diag1(2 * n-1, false);
        vector<bool> diag2(2 * n - 1, false);

        backtrack(board, cols, diag1, diag2, 0, n);
        return result;
    }
};