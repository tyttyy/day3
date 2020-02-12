#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        if (len == 0)return -1;
        int exc = len - 1;
        int l = 0;
        int r = len - 1;
        if (nums[0] > nums[len - 1]) {
            exc = len / 2;
            while (nums[exc] > nums[0] || nums[exc - 1] < nums[0]) {
                if (nums[exc] > nums[0])l = exc + 1;
                if (nums[exc - 1] < nums[0])r = exc - 1;
                exc = (r + l + 1) / 2;
            }
        }
        else {
            if (target < nums[0]) {
                return-1;
            }
            else {
                l = 0;
                r = len - 1;
                exc = (l + r + 1) / 2;
                while (nums[exc] != target) {
                    if (r <= l) return -1;
                    if (nums[exc] > target)r = exc - 1;
                    if (nums[exc] < target)l = exc + 1;
                    if (r < l)return -1;
                    exc = (r + l + 1) / 2;
                }
                return exc;
            }
        }
        if (target < nums[0]) {
            l = exc;
            r = len - 1;
            exc = (l + r + 1) / 2;
            while (nums[exc] != target) {
                if (r <= l) return -1;
                if (nums[exc] > target)r = exc - 1;
                if (nums[exc] < target)l = exc + 1;
                if (r < l)return -1;
                exc = (r + l + 1) / 2;
            }
        }
        else if (target > nums[0]) {
            l = 0;
            r = exc - 1;
            exc = (l + r + 1) / 2;
            while (nums[exc] != target) {
                if (r <= l) return -1;
                if (nums[exc] > target)r = exc - 1;
                if (nums[exc] < target)l = exc + 1;
                if (r < l)return -1;
                exc = (r + l + 1) / 2;
            }
        }
        else exc = 0;
        return exc;
    }
};