class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        // Helper function for DFS
        auto dfs = [&](int i, int j, auto&& dfs_ref) -> void {
            if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != 'O') return;
            board[i][j] = 'A'; // Temporarily mark 'O' as 'A'
            dfs_ref(i + 1, j, dfs_ref);
            dfs_ref(i - 1, j, dfs_ref);
            dfs_ref(i, j + 1, dfs_ref);
            dfs_ref(i, j - 1, dfs_ref);
        };

        // Mark border-connected 'O's as 'A'
        for (int i = 0; i < m; ++i) {
            if (board[i][0] == 'O') dfs(i, 0, dfs);
            if (board[i][n - 1] == 'O') dfs(i, n - 1, dfs);
        }
        for (int j = 0; j < n; ++j) {
            if (board[0][j] == 'O') dfs(0, j, dfs);
            if (board[m - 1][j] == 'O') dfs(m - 1, j, dfs);
        }

        // Convert remaining 'O's to 'X's and 'A's back to 'O's
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == 'A') board[i][j] = 'O';
            }
        }
    }
};
