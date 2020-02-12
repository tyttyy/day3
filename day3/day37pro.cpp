#include<bits/stdc++.h>
using namespace std;
//用深度优先遍历求解，递归求解。往下求解
//即进性下一层的判断，回溯则改变本层值
class Solution {
    bool flag = false;
    vector<vector<char>> unifig;
    void copy(vector<vector<char>>pre, vector<vector<char>>& cur) {
        cur.assign(pre.begin(), pre.end());
    }
    void init(const vector<vector<char>>& board) {
        copy(board, unifig);
    }
    void output(vector<vector<char>>& board) {
        copy(unifig, board);
    }
    bool judge(vector<vector<char>> board, int i, int j, char value) {
        for (int l = 0; l < 9; l++)
            if (value == board[l][j] && l != i)return false;
        for (int r = 0; r < 9; r++)
            if (value == board[i][r] && r != j)return false;
        int i0 = i / 3;
        int j0 = j / 3;
        for (int m = 3 * i0; m < 3 * i0 + 3; m++) {
            for (int n = 3 * j0; n < 3 * j0 + 3; n++) {
                if (m == i && n == j)continue;
                if (value == board[m][n]) return false;
            }
        }
        return true;
    }
    void dfs(vector<vector<char>> board, int i, int j, char value) {
        if (flag) return;
        if (board[i][j] != '.') {
            if (j != 8) {
                dfs(board, i, j + 1, '1');
            }
            else if (i != 8) {
                dfs(board, i + 1, 0, '1');
            }
            else {
                init(board);
                flag = true;
            }
        }
        else {
            if (judge(board, i, j, value)) {
                board[i][j] = value;
                if (j != 8) {
                    dfs(board, i, j + 1, '1');
                }
                else if (i != 8) {
                    dfs(board, i + 1, 0, '1');
                }
                else {
                    init(board);
                    flag = true;
                }
                board[i][j] = '.';
            }
            if (value < '9')
                dfs(board, i, j, char(value + 1));
        }
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        init(board);
        dfs(unifig, 0, 0, '1');
        output(board);

    }

};