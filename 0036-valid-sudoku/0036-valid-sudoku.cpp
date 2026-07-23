class Solution {
public:
    bool isValid(int r, int c, char ch, vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++) {
            if(board[r][i] == ch || board[i][c] == ch) {
                return false;
            }
        }
        int newR = (r / 3) * 3;
        int newC = (c / 3) * 3;
        for (int i = newR; i < newR+3; i++) {
            for (int j = newC; j < newC+3; j++) {
                if(board[i][j] == ch) {
                    return false;
                }
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        for(int r = 0; r < 9; r++) {
            for(int c = 0; c < 9; c++) {
                char ch = board[r][c];
                if(ch != '.') {
                    board[r][c] = '.';
                    bool flag = isValid(r, c, ch, board);
                    board[r][c] = ch;
                    if(!flag) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};