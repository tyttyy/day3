#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if (s.size() == 0)return {};
        if (words.size() == 0) {
            return {};
        }
        int len = words[1].size();
        int alllen = words.size() * len;
        vector<int> result;
        unordered_map<string,int> mmp;
        unordered_map<string, int>::iterator iter;
        vector<int>store_address;
        for (const string& s : words) {
            mmp[s]++;
        }
        for (int i = 0; i < s.size()-alllen+1; i++) {
            string sstr = s.substr(i, len);
            iter = mmp.find(sstr);
            if (iter != mmp.end()) store_address.push_back(i);
        }
        for (int i : store_address) {
            unordered_map<string, int>cmmp(mmp);
            unordered_map<string, int>::iterator citer;
            for (int j = i; j < i + alllen; j += len) {
                string sstr = s.substr(j, len);
                citer = cmmp.find(sstr);
                if (citer != cmmp.end()) {
                    if (citer->second != 0)citer->second--;
                    else break;
                }
                else break;
                if (j == i + alllen - len)result.push_back(i);
            }
        }
        return result;
    }
};