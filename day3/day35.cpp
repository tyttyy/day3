#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int result=0;
        for (const auto &ck:nums) {
            if (ck>=target) {
                break;
            }
            result++;
        }
        return result;
    }
};