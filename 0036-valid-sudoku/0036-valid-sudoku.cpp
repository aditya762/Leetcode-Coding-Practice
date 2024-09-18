class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Use sets to track seen numbers in rows, columns, and 3x3 sub-boxes
        unordered_set<string> seen;

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    char num = board[i][j];

                    // Create keys for rows, columns, and sub-boxes
                    string rowKey = "row_" + to_string(i) + "_" + num;
                    string colKey = "col_" + to_string(j) + "_" + num;
                    string boxKey = "box_" + to_string(i / 3) + "_" + to_string(j / 3) + "_" + num;

                    // Check if the number has already been seen in this row, column, or sub-box
                    if (seen.count(rowKey) || seen.count(colKey) || seen.count(boxKey)) {
                        return false;
                    }

                    // Mark the number as seen in this row, column, and sub-box
                    seen.insert(rowKey);
                    seen.insert(colKey);
                    seen.insert(boxKey);
                }
            }
        }

        return true;
    }
};
