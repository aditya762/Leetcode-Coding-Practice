class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> solutions;
        vector<string> board(n, string(n, '.'));
        vector<int> rows(n, 0), diag1(2 * n - 1, 0), diag2(2 * n - 1, 0);
        
        backtrack(solutions, board, rows, diag1, diag2, 0, n);
        return solutions;
    }
    
private:
    void backtrack(vector<vector<string>> &solutions, vector<string> &board,
                   vector<int> &rows, vector<int> &diag1, vector<int> &diag2,
                   int col, int n) {
        if (col == n) {
            solutions.push_back(board);
            return;
        }
        
        for (int row = 0; row < n; ++row) {
            if (rows[row] || diag1[row + col] || diag2[row - col + n - 1]) continue;
            
            board[row][col] = 'Q';
            rows[row] = diag1[row + col] = diag2[row - col + n - 1] = 1;
            
            backtrack(solutions, board, rows, diag1, diag2, col + 1, n);
            
            board[row][col] = '.';
            rows[row] = diag1[row + col] = diag2[row - col + n - 1] = 0;
        }
    }
};
