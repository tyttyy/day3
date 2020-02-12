#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int len = nums.size();
        if (len == 0) return { -1 ,-1};
        int l=0, r=len-1,pointer=0,lp=-1,rp=-1 ;
        while (l <= r) {
            pointer = (l + r) / 2;
            if (nums[pointer] < target) {
                l = pointer + 1;
            }
            else if (pointer - 1 >= 0) {
                if (nums[pointer - 1] >= target) {
                    r = pointer - 1;
                }
                else {
                    if (nums[pointer] == target)lp = pointer;
                    break;
                }
            }
            else {
                if (nums[pointer] == target)lp = pointer;
                    break;
            }
            
        }
        l = pointer;
        r = len - 1;
        while (l <= r) {
            pointer = (l + r) / 2;
            if (nums[pointer] > target) {
                r = pointer - 1;
            }
            else if (pointer + 1 <= len - 1) {
                if (nums[pointer + 1] <= target) {
                    l = pointer + 1;
                }
                else{ 
                    if (nums[pointer] == target)rp = pointer;
                    break;
                }
            }
            else {
                if (nums[pointer] == target)rp = pointer;
                break;
            }
        }
        return{ lp,rp };

    }
};
