#include<bits/stdc++.h>
using namespace std;
class Solution {
    int len;
    vector<vector<int>> result;
    void dfs(vector<int>&ns,int loc,int trans);
public:
    vector<vector<int>> permute(vector<int>& nums) {
        len = nums.size();
        dfs(nums, 0, 0);
        return result;
    }
};

void Solution::dfs(vector<int>& ns, int loc, int trans)
{
    if (loc != trans) swap(ns[loc], ns[trans]);
    if (loc < len-1) {
        dfs(ns, loc + 1, loc + 1);
    }
    else result.push_back(ns);
    if (loc != trans) swap(ns[loc], ns[trans]);
    if (trans < len - 1) dfs(ns, loc, trans + 1);
}
