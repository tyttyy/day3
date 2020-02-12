#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int len = nums.size();
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        for (int l = 0; l < len- 2; l++) {
            if (nums[l] > 0)break;
            if (l > 0 && nums[l] == nums[l - 1])continue;
            int x = len - 1;
            for (int r = l + 1; r < x;) {
                if (r > l + 1 && nums[r] == nums[r - 1]) {
                    r++;
                    continue;
                }
                if (x < len - 1 && nums[x] == nums[x + 1]) {
                    x--;
                    continue;
                }
                int cresult = nums[l] + nums[x] + nums[r];
                if (cresult == 0) {
                    result.push_back({ nums[l] , nums[x] , nums[r] });
                    r++;
                    x--;
                }
                else if (cresult < 0) {
                    r++;
                }
                else {
                    x--;
                }
                
            }
        }
        return result;
    }
};