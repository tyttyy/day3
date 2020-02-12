#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        int len = s.size();
        int grlen = 2 * numRows - 2;
        string afs;
        for (int i = 0; i < numRows;i++) {
            for (int j = 0; j + i < len;j+=grlen) {
                afs += s[i + j];
                if (i != 0 && i != numRows - 1 && j + grlen - i < len) afs += s[j + grlen - i];
            }
        }
        return afs;
    }
};
