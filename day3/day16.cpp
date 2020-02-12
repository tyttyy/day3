#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int result = -1;
        int dresult = INT_MAX;
        int len = nums.size();
        sort(nums.begin(), nums.end());
        for (int l = 0; l < len - 2; l++) {
            if (nums[0] + nums[1] + nums[2] > target) return nums[0] + nums[1] + nums[2];
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
                if (cresult == target) {
                    return cresult;
                }
                else if (cresult < target) {
                    if (dresult > target - cresult) {
                        dresult = target-cresult;
                        result = cresult;
                    }
                    r++;
                }
                else {
                    if (dresult > cresult-target) {
                        dresult = cresult - target;
                        result = cresult;
                    }
                    x--;
                }

            }
        }
        return result;
    }
};