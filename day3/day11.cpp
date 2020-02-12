#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int len = height.size();
        int maxS = 0;
        int j = len - 1;
        for (int i = 0; i < j; height[i] > height[j] ? j-- : i++) {
            int curheight = min(height[i], height[j]);
            maxS = max(maxS, curheight * (j - i));
            /*int maxr= 0;
            if (height[i] > maxl) {
                maxl = height[i];
                for (int j = len - 1; j > i; j--) {
                    if (height[j] > maxr) {
                        maxr = height[j];
                        int curS = min(maxr, maxl) * (j - i);
                        maxS = curS > maxS ? curS : maxS;
                    }

                }
            }*/

        }
        return maxS;
    }
};