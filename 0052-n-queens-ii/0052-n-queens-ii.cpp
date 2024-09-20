class Solution {
public:
    int totalNQueens(int n) {
        int count = 0;
        vector<int> rows(n, 0), diag1(2 * n - 1, 0), diag2(2 * n - 1, 0);
        backtrack(count, rows, diag1, diag2, 0, n);
        return count;
    }
    
private:
    void backtrack(int &count, vector<int> &rows, vector<int> &diag1, vector<int> &diag2, int col, int n) {
        if (col == n) {
            count++;
            return;
        }
        
        for (int row = 0; row < n; ++row) {
            if (rows[row] || diag1[row + col] || diag2[row - col + n - 1]) continue;
            
            rows[row] = diag1[row + col] = diag2[row - col + n - 1] = 1;
            
            backtrack(count, rows, diag1, diag2, col + 1, n);
            
            rows[row] = diag1[row + col] = diag2[row - col + n - 1] = 0;
        }
    }
};
