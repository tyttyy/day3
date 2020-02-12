#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        int len = nums.size();
        if (len <4)return{};
        if (nums[0] + nums[1] + nums[2] + nums[3] > target) return {};
        for (int a = 0; a < len - 3; a++) {
            if (a > 0 && nums[a] == nums[a - 1])continue;
            for (int b = a + 1; b < len - 2; b++) {
                if (b > a + 1 && nums[b] == nums[b - 1])continue;
                int c = b + 1;
                int d = len - 1;
                while (c<d) {
                    if (c > b + 1 && nums[c] == nums[c - 1]) {
                        c++;
                        continue;
                    }
                    if (d < len - 1 && nums[d] == nums[d + 1]) {
                        d--;
                        continue;
                    }
                    int cresult = nums[a] + nums[b] + nums[c] + nums[d];
                    if (cresult == target) {
                        result.push_back({ nums[a],nums[b],nums[c],nums[d] });
                        c++;
                        d--;
                    }
                    else if (cresult < target) c++;
                    else d--;
                    
                }
            }
        }
        return result;
    }
};