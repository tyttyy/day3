#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int sLenth = s.size();
        int maxSub = 1;
        int startSub = 0;
        vector<vector<int>> rmbLine(sLenth, vector<int>(sLenth));
        for (int i = 0; i < sLenth; i++) {
            rmbLine[i][i] = 1;
            if (i<sLenth-1&&s[i]==s[i+1]) {
                rmbLine[i][i + 1] = 1;
                maxSub = 2;
                startSub = i;
            }
        }
        for (int l = 3; l <=sLenth;l++) {
            if (l>maxSub+3) {
                break;
            }
            for (int i = 0; i + l - 1 < sLenth;i++) {
                int j = i + l - 1;
                if (s[i] == s[j] && rmbLine[i + 1][j - 1] == 1) {
                    rmbLine[i][j] = 1;
                    startSub = i;
                    maxSub = l;
                }
            }
        }
        return s.substr(startSub, maxSub);
    }
};