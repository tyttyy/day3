#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        int len = height.size();
        int l = 0;
        int r = 0;
        int area = 0;
        for (int i = 0; i < len;i++) {
            if (height[i]) {
                l = i;
                break;
            }
        }
        for (int i = l+1; i < len;i++) {
            if (height[i]&&height[i]>height[l]) {
                for (int j = l + 1; j < i; j++) {
                    area += height[l] - height[j];
                }
                l = i;
            }
        }
        for (int i = len-1; i >=0; i--) {
            if (height[i]) {
                r = i;
                break;
            }
        }
        for (int i = r - 1; i >=l; i--) {
            if (height[i] && height[i] > height[r]) {
                for (int j = r - 1; j > i; j--) {
                    area += height[r] - height[j];
                }
                r = i;
            }
        }
        if (l != r) {
            for (int i = l + 1; i < r - 1; i++) {
                area += height[l] - height[i];
            }
        }
        return area;
    }
};