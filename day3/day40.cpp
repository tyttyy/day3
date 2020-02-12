#include<bits/stdc++.h>
using namespace std;
class Solution {
    int len;
    vector<int>::iterator cand;
    int tar;
    vector<vector<int>> result;
    void dfs(vector<int>&pre,int pos,int jud,int sum);
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        len = candidates.size();
        cand = candidates.begin();
        tar = target;
        vector<int> init;
        dfs(init, 0, 0,0);
        return result;
    }
};

void Solution::dfs(vector<int>& pre, int pos, int jud,int sum)
{
    if (jud) {
        sum += *(cand+pos);
        pre.push_back(*(cand + pos));
    }
    if (sum < tar && pos < len - 1) {
        dfs(pre, pos + 1, 0, sum);
    }
    else if (sum == tar) result.push_back(pre);
    if (jud) pre.pop_back();
    if(!jud) dfs(pre, pos, 1, sum);


}
