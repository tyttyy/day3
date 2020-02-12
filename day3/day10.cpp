#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    // ��̬�滮
    bool isMatch(string s, string p) {
        int ns = s.length();
        int np = p.length();
        if (p.empty()) return s.empty();
        vector<vector<bool>> dp(ns + 1, vector<bool>(np + 1, false));
        dp[0][0] = true;
        for (int i = 1; i <= np; i++) {
            if (i - 2 >= 0 && p[i - 1] == '*' && p[i - 2]) {
                dp[0][i] = dp[0][i - 2];
            }
        }

        for (int i = 1; i <= ns; i++) {
            for (int j = 1; j <= np; j++) {
                if (p[j - 1] == s[i - 1] || p[j - 1] == '.')
                    dp[i][j] = dp[i - 1][j - 1];
                if (p[j - 1] == '*') {
                    bool zero, one;
                    if (j - 2 >= 0) {
                        zero = dp[i][j - 2];
                        one = (p[j - 2] == s[i - 1] || p[j - 2] == '.') && dp[i - 1][j];
                        dp[i][j] = zero || one;
                    }
                }
            }
        }
        return dp[ns][np];
    }

    // �ݹ�Ƚ�
    bool isMatch2(string s, string p) {
        return helperMatch(s, p, 0, 0);
    }

    bool helperMatch(string& s, string& p, int i, int j) {
        int ns = s.size();
        int np = p.size();
        if (np == j) {
            if (ns == i) return true;
            return false;
        }
        bool one = false, zero = false;
        if (j + 1 < np && p[j + 1] == '*') {  // ����*ʱ
            zero = helperMatch(s, p, i, j + 2);  // ʹ��0��
            if (!zero && (i < ns) && (p[j] == s[i] || p[j] == '.')) {
                one = helperMatch(s, p, i + 1, j);  // ʹ�ö��
            }
            return zero || one;
        }
        else {
            if ((i < ns) && (p[j] == s[i] || p[j] == '.')) {
                return helperMatch(s, p, i + 1, j + 1);  // ��ǰ�ַ�����ƥ��
            }
            else {
                return false;  // ��ƥ��
            }
        }
        return false;
    }
};
