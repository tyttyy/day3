#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
    int find(string h,string n,int s,int len,int hlen) {
        int result = s;
        if (s + len > hlen)return -1;
        for (int i = 0; i < len; i++) {
            if (h[i + s] != n[i]) {
                result = -1;
            }
        }
        return result;
    }
public:
    int strStr(string haystack, string needle) {
        int len = needle.size();
        if (len == 0) return 0;
        int hlen = haystack.size();
        if (hlen == 0)return -1;
        vector<int> ff;
        for (int i = 0; i < hlen; i++) {
            if (haystack[i] == needle[0]) ff.push_back(i);
        }
        for (const int& i : ff) {
            int result = find(haystack, needle, i, len, hlen);
            if (result > -1)return result;
        }
        return -1;
    }
};