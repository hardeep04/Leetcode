class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool rows[9][9] = {false};
        bool cols[9][9] = {false};
        bool boxes[9][9] = {false};

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '1';
                    int boxIndex = (i / 3) * 3 + (j / 3);
                    if (rows[i][num] || cols[j][num] || boxes[boxIndex][num]) return 0;
                    rows[i][num] = 1;
                    cols[j][num] = 1;
                    boxes[boxIndex][num] = 1;
                }
            }
        }
        return true;
    }
};