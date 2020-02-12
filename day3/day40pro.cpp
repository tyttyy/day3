#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> result;
    vector<int>cand;
    vector<int> times;
    int tar;
    int len;
    void dfs(vector<int>& pre, int pos, int times, int sum);
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        tar = target;
        sort(candidates.begin(), candidates.end());
        len = 0;
        for (int iter : candidates) {
            if (!cand.empty()) {
                if (cand.back() == iter) times[len - 1]++;
                else {
                    cand.push_back(iter);
                    times.push_back(1);
                    len++;
                }
            }
            else {
                cand.push_back(iter);
                times.push_back(1);
                len++;
            }
        }
        
        vector<int> init;
        dfs(init, 0, 0, 0);
        return result;
    }
};

void Solution::dfs(vector<int>& pre, int pos, int times, int sum)
{
    int cursum = sum + times * cand[pos];
    for (int i = 0; i < times; i++) {
        pre.push_back(cand[pos]);
    }
    if (cursum < tar && pos < len - 1) dfs(pre, pos + 1, 0, cursum);
    else if (cursum == tar) result.push_back(pre);
    for (int i = 0; i < times; i++) {
        pre.pop_back();
    }
    if (cursum < tar && times < this->times[pos]) {

        dfs(pre, pos, times + 1, sum);
    }
}
