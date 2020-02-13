#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mmp;
        vector<vector<string>> result;
        string tmp;
        for (string& str : strs) {
            tmp = str;
            sort(tmp.begin(), tmp.end());
            mmp[tmp].push_back(str);
        }
        for (auto cstrs : mmp) {
            result.push_back(cstrs.second);
        }
        return result;
    }
};
