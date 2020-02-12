#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l = 0;
        int r = 1;

        int len = nums.size();
        if (len == 0)return 0;
        int min = nums[0]; 
        while (l + r < len) {
            if (nums[l + 1] == min) {
                nums.erase(nums.begin() + l + 1);
                len--;
            }
            else {
                l++; 
                min = nums[l];
            }
        }
        len -= r - 1;
        return len;
    }
};