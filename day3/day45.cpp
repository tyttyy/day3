#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int jump(vector<int>& nums) {
        int len = nums.size();
        int count = 0;
        int loc = 0;
        while (loc < len - 1) {
            if (loc + nums[loc] >= len - 1) {
                count++;
                break;
            }
            int nloc = 0;
            for (int i = 1; i < nums[loc]; i++) {
                int cloc = loc+i ;
                nloc = nloc+nums[nloc] < cloc+nums[cloc] ? cloc : nloc;
            }
            loc = nloc;
            count++;
        }
        return count;
    }
};