#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int len1 = matrix.size();
        if (len1 == 0) return;
        for (int i = 0; i < len1; i++) {
            for (int j = 0; j <= i; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for (int i = 0; i < len1; i++) {
            for (int j = 0; j < len1 / 2; j++) {
                swap(matrix[i][j], matrix[i][len1 - 1 - j]);
            }
        }
        return;
    }
};