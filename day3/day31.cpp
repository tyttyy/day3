#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();
        int loc = -1;
        for (int i = len - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                loc = i;
                break;
            }
        }
        if (loc == -1) {
            sort(nums.begin(), nums.end()); 
            return;
        }

        for (int i = len - 1; i >= 0; i--) {
            if (nums[i] > nums[loc]) {
                swap(nums[i], nums[loc]); 
                break;
            }
        }
        sort(nums.begin() + loc + 1, nums.end());
        return;
    }
};