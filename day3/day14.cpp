#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string cmperfix;
        int i = 0;
        bool flag = true;
        int size = strs.size();
        if(size == 0||strs[0].size()==0) return "";
        while (i<strs[0].size()) {
            char curc = strs[0][i];
            for (string cpstr:strs) {
                if (!flag) break;
                if (i >= cpstr.size()) flag=false;
                if (cpstr[i] != curc) flag=false;
            }
            if (!flag)break;
            i++;
        }
        if (i == 0) return "";
        cmperfix = strs[0].substr(0, i);
        return cmperfix;

    }
};