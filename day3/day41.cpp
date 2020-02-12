#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if (nums.size() == 0) return 1;
        sort(nums.begin(), nums.end());
        if (nums[0] > 1) return 1;

        int val = 1;
        for (int& iter : nums) {
            if (iter > 0) {
                if (iter == val) val++;
                else if (iter > val) break;
            }

        }
        if (val > 0) return val;
        else return 1;
    }
};