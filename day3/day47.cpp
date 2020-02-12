#include<bits/stdc++.h>
using namespace std;
class Solution {
    int len;
    vector<vector<int>> result;
    void dfs(vector<int>& ns, int loc, int trans, unordered_map<int, int>& mmp);
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        len = nums.size();
        unordered_map<int, int>tmp;
        dfs(nums, 0, 0, tmp);
        return result;
    }
};

void Solution::dfs(vector<int>& ns, int loc, int trans, unordered_map<int, int>& mmp)
{
    if (mmp[ns[trans]] == 0) {
        if (loc != trans) swap(ns[loc], ns[trans]);
        ++mmp[ns[loc]];
        if (loc < len - 1) {
            unordered_map<int, int> nmmp;
            dfs(ns, loc + 1, loc + 1, nmmp);
        }
        else if (loc == len - 1) result.push_back(ns);
        if (loc != trans) swap(ns[loc], ns[trans]);



    }
    if (trans < len - 1) dfs(ns, loc, trans + 1, mmp);
}