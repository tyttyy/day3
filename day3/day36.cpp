#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.')continue;
                for (int l = i + 1; l < 9; l++)
                    if (board[i][j] == board[l][j])return false;
                for (int r = j + 1; r < 9; r++)
                    if (board[i][j] == board[i][r])return false;
                int i0 = i / 3;
                int j0 = j / 3;
                for (int m = 3 * i0; m < 3 * i0 + 3; m++) {
                    for (int n = 3 * j0; n < 3 * j0 + 3; n++) {
                        if (m == i && n == j)continue;
                        if (board[m][n] == board[i][j]) return false;
                    }
                }
            }
        }
        return true;
    }
};